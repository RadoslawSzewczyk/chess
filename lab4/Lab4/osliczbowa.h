#pragma once
# include <fstream>
# include <iostream>

class OsLiczbowa
{
public:
    OsLiczbowa();
    OsLiczbowa(double min, double max);
    OsLiczbowa(const OsLiczbowa& os);
    ~OsLiczbowa();

    double getMin() const { return _min; }
    double getMax() const { return _max; }
    double getInterval() const { return _interval; }

    void setMin(double min) { _min = min; }
    void setMax(double max) { _max = max; }
    void setInterval(double interval) { _interval = interval; }

    void print() const;

    static void printCount();

    friend std::ostream& operator<<(std::ostream& os, const OsLiczbowa& osLicz);

    OsLiczbowa& operator=(const OsLiczbowa& os);

    OsLiczbowa operator*=(const double a);
    OsLiczbowa operator/=(const double a);

private:
    double _min;
    double _max;
    double _interval;

    static int _count;



};