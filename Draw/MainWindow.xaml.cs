using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Drawing;

namespace Draw
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void Draw_Click(object sender, RoutedEventArgs e)
        {
            Quadrangle A = new Quadrangle();
            System.Windows.Point[] P = new System.Windows.Point[4];
            if (double.TryParse(X1.Text, out _) && double.TryParse(X2.Text, out _) && double.TryParse(X3.Text, out _) && double.TryParse(X4.Text, out _) &&
                double.TryParse(Y1.Text, out _) && double.TryParse(Y2.Text, out _) && double.TryParse(Y3.Text, out _) && double.TryParse(Y4.Text, out _))
            {
                P[0].X = Convert.ToDouble(X1.Text);
                P[0].Y = Convert.ToDouble(Y1.Text);
                P[1].X = Convert.ToDouble(X2.Text);
                P[1].Y = Convert.ToDouble(Y2.Text);
                P[2].X = Convert.ToDouble(X3.Text);
                P[2].Y = Convert.ToDouble(Y3.Text);
                P[3].X = Convert.ToDouble(X4.Text);
                P[3].Y = Convert.ToDouble(Y4.Text);

                /*смещаем одну из вершин к началу координат и вместе с ней все остальные координаты
                затем смещаем четырехугольник из начала к середине
                */

                for (int i = 1; i < 4; i++)
                {
                    P[i].X = 160.5 - P[0].X + P[i].X;
                    P[i].Y = 168 + P[0].Y - P[i].Y;
                }

                P[0].X = 160.5;
                P[0].Y = 168;

                /*P[1].X += Additional_Offset(Convert.ToDouble(X2.Text));
                P[1].Y += Additional_Offset(Convert.ToDouble(Y2.Text));
                P[2].X += Additional_Offset(Convert.ToDouble(X3.Text));
                P[2].Y += Additional_Offset(Convert.ToDouble(Y3.Text));
                P[3].X += Additional_Offset(Convert.ToDouble(X4.Text));
                P[3].Y += Additional_Offset(Convert.ToDouble(Y4.Text));*/

                A[0, 0] = Convert.ToDouble(X1.Text);
                A[0, 1] = Convert.ToDouble(Y1.Text);
                A[1, 0] = Convert.ToDouble(X2.Text);
                A[1, 1] = Convert.ToDouble(Y2.Text);
                A[2, 0] = Convert.ToDouble(X3.Text);
                A[2, 1] = Convert.ToDouble(Y3.Text);
                A[3, 0] = Convert.ToDouble(X4.Text);
                A[3, 1] = Convert.ToDouble(Y4.Text);
                Area.Text = Convert.ToString(A.AreaOfQuadrangle());
                Perimeter.Text = Convert.ToString(A.PerimeterOfQuadrangle());
                Square.Text = Convert.ToString(A.Square());
                Figure.Points.Clear();
                Figure.Points.Add(P[0]);
                Figure.Points.Add(P[1]);
                Figure.Points.Add(P[2]);
                Figure.Points.Add(P[3]);
            }
            else
            {
                Area.Text = "Incorrect values";
                Perimeter.Text = "Incorrect values";
                Square.Text = "Incorrect values";
            }
        }
    }
}
