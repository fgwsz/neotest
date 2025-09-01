#!/usr/bin/env python3
# -*- coding: utf-8 -*-

def generate_pp_inc_file(filename="pp_inc.h", max_value=1024):
    """
    生成 pp_inc.h 文件，包含从 0 到 max_value-1 的递增宏定义
    
    Args:
        filename (str): 输出文件名
        max_value (int): 最大宏定义值
    """
    with open(filename, 'w') as f:
        # 写入文件头部
        f.write("#ifndef NEOTEST_PP_INC_H\n")
        f.write("#define NEOTEST_PP_INC_H\n\n")
        
        # 生成递增宏定义
        for i in range(max_value):
            f.write(f"#define NEOTEST_PP_INC_{i} {i + 1}\n")
        
        # 写入文件尾部
        f.write("\n#endif // NEOTEST_PP_INC_H\n")
    
    print(f"成功生成 {filename}，包含 NEOTEST_PP_INC_0 到 NEOTEST_PP_INC_{max_value-1} 的宏定义")

def generate_pp_dec_file(filename="pp_dec.h", max_value=1024):
    """
    生成 pp_dec.h 文件，包含从 max_value 到 1 的递减宏定义
    每个 PP_DEC_N 的值为 N-1
    
    Args:
        filename (str): 输出文件名
        max_value (int): 最大起始值
    """
    with open(filename, 'w') as f:
        # 写入文件头部
        f.write("#ifndef NEOTEST_PP_DEC_H\n")
        f.write("#define NEOTEST_PP_DEC_H\n\n")
        
        # 生成递减宏定义
        for i in range(max_value, 0, -1):
            f.write(f"#define NEOTEST_PP_DEC_{i} {i-1}\n")
        
        # 写入文件尾部
        f.write("\n#endif // NEOTEST_PP_DEC_H\n")
    
    print(f"成功生成 {filename}，包含 NEOTEST_PP_DEC_{max_value} 到 NEOTEST_PP_DEC_1 的宏定义")

def generate_pp_bool_file(filename="pp_bool.h", max_value=1024):
    """
    生成 pp_bool.h 文件，包含从 0 到 max_value 的递增宏定义
    
    Args:
        filename (str): 输出文件名
        max_value (int): 最大宏定义值
    """
    with open(filename, 'w') as f:
        # 写入文件头部
        f.write("#ifndef NEOTEST_PP_BOOL_H\n")
        f.write("#define NEOTEST_PP_BOOL_H\n\n")
        
        f.write(f"#define NEOTEST_PP_BOOL_0 0\n")
        # 生成递增宏定义
        for i in range(1,max_value+1):
            f.write(f"#define NEOTEST_PP_BOOL_{i} 1\n")
        
        # 写入文件尾部
        f.write("\n#endif // NEOTEST_PP_BOOL_H\n")
    
    print(f"成功生成 {filename}，包含 NEOTEST_PP_BOOL_0 到 NEOTEST_PP_BOOL_{max_value} 的宏定义")

if __name__ == "__main__":
    # 生成文件，最大值为1024
    generate_pp_inc_file(max_value=1024)
    generate_pp_dec_file(max_value=1024)
    generate_pp_bool_file(max_value=1024)
