#include <stdio.h>
#include<stdlib.h>
int lengthOfLongestSubstring(char* s);
int main(void) {
    char str1[] = "Hello,world!I know there is a lot to learn.";
    char str2[] = "abcabcbb";
    int n = lengthOfLongestSubstring(str2);
    printf("The length is %d", n);
    return 0;
}



int lengthOfLongestSubstring(char* s) {
    // 防御性判断：空指针直接返回0
    if (s == NULL) return 0;

    int len = 0;
    while (s[len] != '\0') { len++; }

    int flag = 1;
    int window_size = len;
    int n = 0; // 初始化返回值，避免未定义行为

    while (flag && window_size > 0) {
        // 分配内存：+1 用于存储字符串结束符 '\0'
        char* word = (char*)malloc((window_size + 1) * sizeof(char));

        if (word == NULL) {puts("内存分配失败。");break;}

        flag = 0; // 假设当前窗口大小存在无重复子串

        // 遍历所有当前长度的子串
        for (int i = 0; i <= len - window_size; i++) {
            int k = 0; 

            // 安全拷贝子串
            for (int j = i; j < i + window_size; j++) {
                word[k++] = s[j];
            }
            word[k] = '\0'; 

            // 检查当前子串是否有重复字符
            int has_dup = 0;
            for (int x = 0; x < window_size && !has_dup; x++) {
                for (int y = x + 1; y < window_size && !has_dup; y++) {
                    if (word[x] == word[y]) {
                        has_dup = 1; // 标记有重复
                    }
                }
            }

            // 无重复则找到最长子串，直接跳出所有循环
            if (!has_dup) {
                n = window_size;
                flag = 0; // 终止外层while循环
                break;
            }
            else { window_size--; }
            
          
        }
        free(word);
     
        
    }

    return n;
}