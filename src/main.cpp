#include "../include/SpectralIndices_interface.h"
#include <iomanip>
using namespace std;

// 以下为一个计算NDVI的示例，可以作为如何使用本函数库的参考示例
//  testing
int main(int argc, const char **argv)
{
    int raw[5][2][2] = 
    {
        {
            {390,0},
            {164,3047}
        },
        {
            {638,304},
            {372,3115}
        },
        {
            {858,562},
            {637,3153}
        },
        {
            {2931,3288},
            {3329,3562}
        },
        {
            {2772,3346},
            {3126,3339}
        }
    };
    // double result[2][2];
    double **result = new double *[2];
    for (int i = 0; i < 2; ++i)
    {
        result[i] = new double[2];
    }
    double a[5] = {420.0348, 650.4232, 555.0990, 859.4069, 1019.4377};
    int ***raw_data = new int **[2];
    for (int i = 0; i < 5; ++i)
    {
        raw_data[i] = new int *[2];
        for (int j = 0; j < 2; ++j)
        {
            raw_data[i][j] = new int[5];
            for (int k = 0; k < 2; ++k)
            {
                raw_data[i][j][k] = raw[i][j][k];
            }
        }
    }
    spectral_index_calculation(raw_data, 5, 2, 2, a, RDVI, result);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "ndvi is " << setprecision(8) << result[i][j] << endl;
        }
    }
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            delete[] raw_data[i][j];
        }
        delete[] raw_data[i];
    }
    delete[] raw_data;
    for (int i = 0; i < 2; ++i)
    {
        delete[] result[i];
    }
    delete[] result;
    return 0;
}