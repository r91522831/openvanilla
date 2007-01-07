using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace CSharpFormLibrary
{
    public partial class IMECompRichForm : Form
    {
        private const int WM_MOUSEACTIVATE = 0x0021;
        private const int MA_NOACTIVATE = 0x0003;
        private const int MA_NOACTIVATEANDEAT = 0x0004;

        //private int caretWidth = 0;
        //just give the caret a small point;
        private int caretWidth = 2;
        private int CurrentAll = 0; //�{�binput�r�ƪ��j�p
        private int currentAllCompStrLength = 0;
        private Label label2;//composition window�����Ϫ��j�p
        private int singleCaretHightlight = 0;
        private int caretPosX = 0;

        private int compSelStart = 0;
        private int compSelEnd = 0;
        
        public IMECompRichForm()
        {
            InitializeComponent();
        }
        protected override void WndProc(ref Message m)
        {
            if (m.Msg == WM_MOUSEACTIVATE)
            {
                m.Result = (IntPtr)MA_NOACTIVATEANDEAT;
                return;
            }
            base.WndProc(ref m);
        }
        public void ShowNoActive()
		{
            if(!this.Visible)
			    UtilFuncs.SetVisibleNoActivate(this, true); // true to show. 
		}
		public void HideNoActive()
		{
            if (this.Visible)
			    UtilFuncs.SetVisibleNoActivate(this, false); // false to hide.  
		}
		public void ClearComp()
		{
			this.richTextBox1.Clear();
		}
		public void SetLocation(int x, int y)
		{
			this.Location = new Point(x,y);
		}
		public void SetComp(string inputs)
		{

			if(inputs==null) return;

            
            //if (inputs == null || this.textBox1.Text == inputs) return;
            /* *** Comments due to OVIME.VC8.sln <Jaimie> *************/
            /* *** postpone this merge until fully upgrade to VC8 *****/
            /*
            Graphics g = this.richTextBox1.CreateGraphics();
            Size s;
            Size proposedSize1 = new Size();
            TextFormatFlags tff1;

            //1st method for get the exact composition length
#if true
            System.Drawing.StringFormat format = new System.Drawing.StringFormat();

            System.Drawing.RectangleF rect = new System.Drawing.RectangleF(0, 0, 1000, 100);

            System.Drawing.CharacterRange[] ranges = 
             { new System.Drawing.CharacterRange(0, inputs.Length) };
            System.Drawing.Region[] regions = new System.Drawing.Region[1];

            format.SetMeasurableCharacterRanges(ranges);

            regions = g.MeasureCharacterRanges(inputs, this.richTextBox1.Font, rect, format);
            rect = regions[0].GetBounds(g);

            //mark the next line for dynamic composition window length setting.                                              
            //currentAllCompStrLength = (int)(rect.Right + 1.0f);
            currentAllCompStrLength = (int)(rect.Right);
            g.Dispose();
            //CurrentAll = inputs.Length;
            //this.Width = (int)(rect.Right + 2.0f);  
#endif
            */
            this.richTextBox1.Text = inputs;            
            Point pt = this.richTextBox1.GetPositionFromCharIndex(this.richTextBox1.Text.Length);
            this.Width = pt.X+10;                        
        }

        public int GetHeight()
        {
            try
            {
                System.Diagnostics.Debug.WriteLine("c# comp height = " + this.Height);
            }
            catch (Exception e)
            {
                System.Diagnostics.Debug.WriteLine(e.StackTrace);
            }
            return this.Height;
        }
        public int GetCaretPosX()
        {
            try
            {
                System.Diagnostics.Debug.WriteLine("c# comp GetCaretPosX = " + caretPosX);
            }
            catch (Exception e)
            {
                System.Diagnostics.Debug.WriteLine(e.StackTrace);
            }
            return caretPosX;
        }

		public void SetCaretX(int x)
		{
            //System.Diagnostics.Debug.WriteLine("set caret:" + x);
            //System.Diagnostics.Debug.WriteLine("current char pos:" + this.richTextBox1.GetFirstCharIndexFromLine(0));
            if (this.richTextBox1.GetFirstCharIndexFromLine(0) > 0)
            {
                Point pt = this.richTextBox1.GetPositionFromCharIndex(x);
                caretPosX = pt.X + 1;
            }
            else
                caretPosX = 1;
            //System.Diagnostics.Debug.WriteLine("caret set = " + caretPosX);
            //caretPosX = (currentAllCompStrLength) * (x) / CurrentAll;
    
            if (compSelStart == compSelEnd) //�w�g�զr
            {
                if (compSelStart == 0)  compSelStart = 1;
                //System.Diagnostics.Debug.WriteLine("if, before select");
                if(this.richTextBox1.GetFirstCharIndexFromLine(0) > 0)
                    this.richTextBox1.Select(compSelStart - 1, 1);
                //System.Diagnostics.Debug.WriteLine("if, after select");
                //this.richTextBox1.SelectionBackColor = System.Drawing.Color.Blue;
                //this.richTextBox1.SelectionColor = Color.White;                
                this.label1.Left = caretPosX;
            }
            else //���b�զr
            {
                System.Diagnostics.Debug.WriteLine("else, before select");
                this.richTextBox1.Select(compSelStart, compSelEnd - compSelStart);
                System.Diagnostics.Debug.WriteLine("else, after select");
                //this.richTextBox1.SelectionBackColor = System.Drawing.Color.Black;
                this.richTextBox1.SelectionColor = Color.Red;
                //this.richTextBox1.Width = this.richTextBox1.Width;                
            }
            
        }

        public void CompMarkFrom(int x)
        {
            compSelStart = x;
        }
        
        public void CompMarkTo(int x)
        {
            compSelEnd = x;
        }


    }
}