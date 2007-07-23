using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Xml;

namespace OVPreference.CS2
{
    public partial class OVPrefrence : Form
    {
        private List<OVConfig> m_ovConfList = new List<OVConfig>();
        private static string m_ovConfPath =
            Environment.GetFolderPath(
                Environment.SpecialFolder.ApplicationData) +
            System.IO.Path.DirectorySeparatorChar +
            "OpenVanilla" + System.IO.Path.DirectorySeparatorChar +
            "config.xml";
        private XmlDocument m_ovConfDom = new XmlDocument();

        public OVPrefrence()
        {
            InitializeComponent();

            LoadData();

            SortModules();

            SetUI();
        }

        private void SortModules()
        {
            ComparerOVConfig comparer = new ComparerOVConfig();
            comparer.SortBy = EnumSortBy.Priority;
            m_ovConfList.Sort(comparer);
            //<comment author='b6s'>
            // The following code is useless
            // since C# does not have a stable sort.
            //comparer.SortBy = EnumSortBy.Enabled;
            //m_ovConfList.Sort(comparer);
            //</commnet>
        }

        private void SetUI()        
        {
            PanelModuleList pnModuleList = new PanelModuleList(m_ovConfDom);
            foreach (OVConfig conf in m_ovConfList)
            {
                bool isEnabled = false;
                if (conf.settings.ContainsKey("enable"))
                    isEnabled =
                        Convert.ToBoolean(
                            Convert.ToInt32(
                                conf.settings["enable"]));
                pnModuleList.AddModule(conf.moduleName, isEnabled);

                if (conf.moduleName.StartsWith("OVIMGeneric"))
                    AddTabGeneric(conf, m_ovConfDom);
                if (conf.moduleName.Equals("OVIMPhonetic"))
                    AddTabPhonetic(conf, m_ovConfDom);
                if (conf.moduleName.Equals("OVIMPOJ-Holo"))
                    AddTabPOJ(conf, m_ovConfDom);
                if (conf.moduleName.Equals("OVIMTibetan"))
                    AddTabTibetan(conf, m_ovConfDom);
                if (conf.moduleName.StartsWith("OVIMTobacco"))
                    AddTabTobacco(conf, m_ovConfDom);
                if (conf.moduleName.Equals("TLIM"))
                    AddTabTLIM(conf, m_ovConfDom);
            }
            if (m_ovConfList.Count > 1)
                this.AddTabModuleList(pnModuleList);
        }

        protected void AddTabModuleList(PanelModuleList pnModuleList)
        {
            TabPage tpModuleList = new TabPage("Module List");
            tpModuleList.Controls.Add(pnModuleList);
            //<comment author='b6s'>
            IntPtr h = this.m_tcSelf.Handle;
            // It's a bug that TabControl.Handle has to be touched manually
            // Before TabControl.TabPages.Insert() is invoked.
            this.m_tcSelf.TabPages.Insert(0, tpModuleList);
            //</comment>
            this.m_tcSelf.SelectTab(0);

            this.SetSize(tpModuleList);
        }

        protected void AddTabGeneric(OVConfig conf, XmlDocument confDom)
        {
            PanelGeneric pnGeneric = new PanelGeneric();
            pnGeneric.Init(conf, confDom);
            AddTab(pnGeneric, conf.moduleName);
        }

        protected void AddTabPhonetic(OVConfig conf, XmlDocument confDom)
        {
            PanelPhonetic pnPhonetic = new PanelPhonetic();
            pnPhonetic.Init(conf, confDom);
            AddTab(pnPhonetic, conf.moduleName);
        }

        protected void AddTabPOJ(OVConfig conf, XmlDocument confDom)
        {
            PanelPOJ pnPOJ = new PanelPOJ();
            pnPOJ.Init(conf, confDom);
            AddTab(pnPOJ, conf.moduleName);
        }

        protected void AddTabTibetan(OVConfig conf, XmlDocument confDom)
        {
            PanelTibetan pnTibetan = new PanelTibetan();
            pnTibetan.Init(conf, confDom);
            AddTab(pnTibetan, conf.moduleName);
        }

        protected void AddTabTobacco(OVConfig conf, XmlDocument confDom)
        {
            PanelTobacco pnTobacco = new PanelTobacco();
            pnTobacco.Init(conf, confDom);
            AddTab(pnTobacco, conf.moduleName);
        }

        protected void AddTabTLIM(OVConfig conf, XmlDocument confDom)
        {
            PanelTLIM pnTLIM = new PanelTLIM(conf, confDom);
            AddTab(pnTLIM, conf.moduleName);
        }

        private void AddTab(Control panel, string name)
        {
            TabPage tp = new TabPage(name);
            tp.Controls.Add(panel);
            this.m_tcSelf.TabPages.Add(tp);
            this.SetSize(panel);
        }

        private void SetSize(Control innerControl)
        {
            if (innerControl == null) return;
            //<comment author='b6s'>
            innerControl.ClientSize = innerControl.PreferredSize;
            // It's a trick to change the smaller ClientSize to
            // a larger PreferredSize to reserve more spaces.
            //</comment>

            //<comment author='b6s'>
            // A while loop insteads recusive calls of SetSize()
            // since the size of Parent must connect to Child's.
            //</comment>
            while (innerControl.Parent != null)
            {
                if (innerControl.Parent.ClientSize.Width
                        < innerControl.PreferredSize.Width
                    ||
                    innerControl.Parent.ClientSize.Height
                        < innerControl.PreferredSize.Height)
                {
                    //<comment author='b6s'>
                    innerControl.Parent.ClientSize =
                        innerControl.PreferredSize;
                    innerControl.Parent.ClientSize =
                        innerControl.Parent.PreferredSize;
                    // It's a trick to change ClientSize twice.
                    //</comment>
                }
                
                innerControl = innerControl.Parent;
            }
        }

        private void LoadData()
        {
            //MessageBox.Show("Loads XML config here");
            m_ovConfDom.Load(m_ovConfPath);
            OVConfig ovConfSet = new OVConfig();
            using (XmlReader ovConfReader = XmlReader.Create(m_ovConfPath))
            {
                #region Read Elements
                while (ovConfReader.Read())
                {
                    ovConfReader.MoveToElement();
                    /*
                    System.Diagnostics.Debug.WriteLine("Elem:" +
                        ovConfReader.Name + ":=" +
                        ovConfReader.Value);
                     */

                    bool isDictStart = false, isDictEnd = false;
                    bool isKey = false;
                    if (ovConfReader.Name == "dict")
                    {
                        if (ovConfReader.IsStartElement())
                            isDictStart = true;
                        else
                            isDictEnd = true;
                    }
                    else if (ovConfReader.Name == "key")
                        isKey = true;

                    if (isDictEnd)
                        m_ovConfList.Add(ovConfSet);

                    string attrNameTemp = "";
                    #region Read attributes
                    while (ovConfReader.MoveToNextAttribute())
                    {
                        /*
                        System.Diagnostics.Debug.WriteLine("Attr:" +
                            ovConfReader.Name + ":=" +
                            ovConfReader.Value);
                         */
                        if (isDictStart)
                        {
                            ovConfSet = new OVConfig();
                            ovConfSet.moduleName = ovConfReader.Value;
                        }
                        else if (isKey)
                        {
                            if (ovConfReader.Name == "name")
                                attrNameTemp = ovConfReader.Value;
                            else if (ovConfReader.Name == "value")
                            {
                                ovConfSet.settings.Add(
                                    attrNameTemp, ovConfReader.Value);
                                attrNameTemp = "";
                            }
                        }
                    }
                    #endregion
                }
                #endregion
            }
        }

        private void SaveData()
        {
            //MessageBox.Show("i=" + m_inputType + ", o=" + m_outputType + ", m_diacriticOption=" + m_diacriticOption + ", m_doNormalize=" + m_doNormalize + ", m_doForcePOJStyle=" + m_doForcePOJStyle);
            m_ovConfDom.Save(m_ovConfPath);
            this.Close();
        }

        private void m_btSave_Click(object sender, EventArgs e)
        {
            SaveData();
        }
    }
}