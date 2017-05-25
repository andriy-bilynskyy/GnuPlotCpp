#ifndef CPLOT2D_H_
#define CPLOT2D_H_

#include <stdint.h>
#include <vector>

/**
 * gnuplot .cpp front-end class
 */
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
    void setXlable(const char * label);
    void setYlable(const char * label);
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
    const char                   * m_xlabel;
    const char                   * m_ylabel;
    static const char            * m_gnuplotPipe;

    CPlot2D(const CPlot2D &);
    CPlot2D & operator=(const CPlot2D &);
};

#endif
