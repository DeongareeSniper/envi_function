#include "../include/SpectralIndices.h"
using namespace std;


/// @brief 
/// @param raw_data 原始数据三维数组指针
/// @param x 三维数组长度，原始数据波段数
/// @param y 三维数组宽度，像素横坐标
/// @param z 三维数组深度，像素纵坐标
/// @param value_array_of_all_band 原始数据每个波段的中心波长数组
/// @param spectralindices_index 光谱指数索引（详情见SpectralIndices_math.h）
/// @param result 存放结果的二维数组指针
/// @return 成功返回1，失败返回0
int spectral_index_calculation(int ***raw_data, int x, int y, int z, double *value_array_of_all_band,
                               SpectralIndices spectralindices_index, double **result);

