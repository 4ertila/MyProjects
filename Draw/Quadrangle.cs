using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Math;

namespace Draw
{
    public class Quadrangle
    {
        private double a;
        private double b;
        private double c;
        private double d;
        private double[,] Points;

        public double this[int i, int j]
        {
            get
            {
                return Points[i, j];
            }
            set
            {
                Points[i, j] = value;
                DefSides();
            }
        }

        public Quadrangle()
        {
            a = 0;
            b = 0;
            c = 0;
            d = 0;
            Points = new double[4, 2];
        }

        public Quadrangle(double[,] Arr)
        {
            Points = new double[4, 2];
            for (int i = 0; i < 4; i++)
            {
                Points[i, 0] = Arr[i, 0];
                Points[i, 1] = Arr[i, 1];
            }
            DefSides();
        }

        public void Init(double[,] Arr)
        {
            Points = new double[4, 2];
            for (int i = 0; i < 4; i++)
            {
                Points[i, 0] = Arr[i, 0];
                Points[i, 1] = Arr[i, 1];
            }
            DefSides();
        }

        public void Init(Quadrangle quad)
        {
            Points = new double[4, 2];
            for (int i = 0; i < 4; i++)
            {
                Points[i, 0] = quad[i, 0];
                Points[i, 1] = quad[i, 1];
            }
            DefSides();
        }

        private void DefSides()
        {
            a = Sqrt(Pow(Points[1, 0] - Points[0, 0], 2) + Pow(Points[1, 1] - Points[0, 1], 2));
            b = Sqrt(Pow(Points[2, 0] - Points[1, 0], 2) + Pow(Points[2, 1] - Points[1, 1], 2));
            c = Sqrt(Pow(Points[3, 0] - Points[2, 0], 2) + Pow(Points[3, 1] - Points[2, 1], 2));
            d = Sqrt(Pow(Points[0, 0] - Points[3, 0], 2) + Pow(Points[0, 1] - Points[3, 1], 2));
        }

        public override string ToString()
        {
            string str = "";
            str += a + " " + b + " " + c + " " + d + " ";
            for (int i = 0; i < 4; i++)
            {
                str += "(" + Points[i, 0] + ";";
                str += Points[i, 1] + ")" + " ";
            }
            return str;
        }

        public double PerimeterOfQuadrangle()
        {
            return a + b + c + d;
        }

        public double AreaOfQuadrangle()
        {
            double p = PerimeterOfQuadrangle() / 2;
            return Sqrt((p - a) * (p - b) * (p - c) * (p - d));
        }

        public bool Square()
        {
            return (a == b && a == c && a == d);
        }
    }
}
