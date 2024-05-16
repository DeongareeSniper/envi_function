#include "../include/SpectralIndices_interface.h"
using namespace std;


//以下为一个计算NDVI的示例，可以作为如何使用本函数库的参考示例
// testing
int main(int argc, const char **argv)
{
    int raw[2][2][5] = {
        {{0, 289, 0, 3550, 0},
         {0, 232, 0, 2769, 0}},
        {{0, 1453, 0, 1986, 0},
         {0, 3273, 0, 3419, 0}}};
    // float result[2][2];
    float **result = new float *[2];
    for (int i = 0; i < 2; ++i)
    {
        result[i] = new float[2];
    }
    float a[5] = {600, 649, 800, 850, 960};
    int ***raw_data = new int **[2];
    for (int i = 0; i < 2; ++i)
    {
        raw_data[i] = new int *[2];
        for (int j = 0; j < 2; ++j)
        {
            raw_data[i][j] = new int[5];
            for (int k = 0; k < 5; ++k)
            {
                raw_data[i][j][k] = raw[i][j][k];
            }
        }
    }
    spectral_index_calculation(raw_data, 2, 2, 5, a, NDVI, result);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "ndvi is " << result[i][j] << endl;
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