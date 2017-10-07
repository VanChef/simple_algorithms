
/*
链接：https://www.nowcoder.com/questionTerminal/9d5fbe7750a34d0b91c73943f93b2d7d
来源：牛客网

如果一个单词通过循环右移获得的单词，我们称这些单词都为一种循环单词。 例如：picture 和 turepic 就是属于同一种循环单词。
现在给出n个单词，需要统计这个n个单词中有多少种循环单词。 
输入描述:

输入包括n+1行：
 第一行为单词个数n(1 ≤ n ≤ 50)
 接下来的n行，每行一个单词word[i]，长度length(1 ≤ length ≤ 50)。由小写字母构成


输出描述:

输出循环单词的种数
示例1
输入

5 picture turepic icturep word ordw
输出

2

分析：
首先要解决的一个问题就是：怎样判断两个字符串是不是互为循环单词？
一个trick：如果两个单词长度相同，并且如果将其中一个重复一遍，重复结果包含另一个单词，则这两个单词互为循环单词

如：picture和turepic，turepic重复一遍即为：turepicturepic，该单词中包含picture，可以判断出这两个单词互为循环单词
*/

int rotate_word_count(string &in)
{
    size_t pos = in.find("\n");
    size_t start = 0;
    size_t count = atoi(in.substr(start, pos - start));


}


