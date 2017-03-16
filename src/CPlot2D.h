#ifndef CPLOT2D_H_
#define CPLOT2D_H_

#include <stdint.h>
#include <vector>

class CPlot2D
{
public:

    CPlot2D();
    ~CPlot2D();
    void addPoint(double x, double y);
    void resetData();
    void resetPlot();
    void setColor(uint32_t rrggbb);
    void setTitle(const char * title);
    void setXlable(const char * title);
    void setYlable(const char * title);
    static bool checkGNUPLOT();
    void draw();

private:

    typedef struct Point2D
    {
        Point2D() : x(0), y(0) {}
        Point2D(double _x, double _y) : x(_x), y(_y) {}
        double x;
        double y;
    }Point2D_t;

    std::vector<Point2D_t>         m_data;
    uint32_t                       m_color;
    const char                   * m_title;
    const char                   * m_xlable;
    const char                   * m_ylable;
    static const char            * m_gnuplotPipe;

    CPlot2D(const CPlot2D &);
    CPlot2D & operator=(const CPlot2D &);
};

#endif /* CPLOT2D_H_ */
