#include <iostream>
#include "CPlot2D.h"

#include <math.h>


int main()
{
    if(CPlot2D::checkGNUPLOT())
    {
        CPlot2D plot;
        plot.setXlable("time, mS");
        plot.setYlable("voltage, V");
        double x = -M_PI;
        while(x <= M_PI)
        {
            plot.addPoint(x, sin(x));
            x += .0001;
        }
        plot.setColor(0xFF0000);
        plot.setTitle("sin(x)");
        plot.draw();

        plot.resetData();
        x = -M_PI;
        while(x <= M_PI)
        {
            plot.addPoint(x, cos(x));
            x += .0001;
        }
        plot.setColor(0x00FF00);
        plot.setTitle("cos(x)");
        plot.draw();
    }
    else
    {
        std::cout << "gnuplot error" << std::endl;
    }

    return 0;
}


