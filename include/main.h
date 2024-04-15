



// 这里选择__DEBUG__作为开关，注释掉下面这一行，则可以直接关闭程序中的DEBUG输出
////////////////////////////////
#define __DEBUG__
////////////////////////////////
#ifdef __DEBUG__  
// 如果对__DEBUG__进行定义，则将对DEBUG(string)中的内容按照cout的方式进行输出

#define DEBUG(string) cout<< (string)
#else  
// 如果没有对__DEBUG__进行定义，则DEBUG(string)会被替换为空，所以DEBUG语句将不会输出
#define DEBUG(format,...)  
#endif  



