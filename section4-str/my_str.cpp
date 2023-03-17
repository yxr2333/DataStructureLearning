#include <bits/stdc++.h>
#define N 1000
using namespace std;
struct Str
{
    char data[N];
    int length;
    Str()
    {
        length = 0;
        memset(data, 0, sizeof(data));
    }
    Str(const char *s)
    {
        if (strlen(s) > N)
        {
            cout << "�ַ������ȳ�������" << endl;
            return;
        }
        length = strlen(s);
        for (int i = 0; i < length; i++)
        {
            data[i] = s[i];
        }
    }
    Str(string str)
    {
        if (str.length() > N)
        {
            cout << "�ַ������ȳ�������" << endl;
            return;
        }
        length = str.length();
        for (int i = 0; i < length; i++)
        {
            data[i] = str[i];
        }
    }
    void assign(char *s)
    {
        if (strlen(s) > N)
        {
            cout << "�ַ������ȳ�������" << endl;
            return;
        }
        length = strlen(s);
        for (int i = 0; i < length; i++)
        {
            data[i] = s[i];
        }
    }
    void copy(char *target)
    {
        for (int i = 0; i < length; i++)
        {
            target[i] = data[i];
        }
    }
    bool empty()
    {
        return length == 0;
    }
    int compare(Str s)
    {
        int i = 0;
        while (i < length && i < s.length)
        {
            if (data[i] < s.data[i])
            {
                return -1;
            }
            else if (data[i] > s.data[i])
            {
                return 1;
            }
            i++;
        }
        if (length < s.length)
        {
            return -1;
        }
        else if (length > s.length)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    /**
     * ���� index �����ַ��� str �������ַ����е�һ�γ��� str ������
     *
     * @param str Ҫ�������ַ���
     *
     * @return ���ַ�����һ�γ��ֵ�������
     */
    int index(Str str)
    {
        int i = 0;
        int len = str.length;
        Str tmpStr;
        while (i < length - len + 1)
        {
            tmpStr.assign(subString(i, len));
            if (tmpStr.compare(str) == 0)
            {
                return i;
            }
            i++;
        }
        return -1;
    }
    int len()
    {
        return length;
    }
    /**
     *
     *
     * @param pos �Ӵ�����ʼλ��
     * @param len �Ӵ��ĳ���
     *
     * @return ָ�����ַ�����ָ�롣
     */
    char *subString(int pos, int len)
    {
        if (pos < 0 || pos >= length || len < 0 || len > length - pos)
        {
            cout << "��������" << endl;
            return NULL;
        }
        char *s = new char[len + 1];
        for (int i = 0; i < len; i++)
        {
            s[i] = data[pos + i];
        }
        s[len] = '\0';
        return s;
    }
    char *concat(Str s)
    {
        if (length + s.length > N)
        {
            cout << "�ַ������ȳ�������" << endl;
            return NULL;
        }
        char *s1 = new char[length + s.length + 1];
        for (int i = 0; i < length; i++)
        {
            s1[i] = data[i];
        }
        for (int i = 0; i < s.length; i++)
        {
            s1[length + i] = s.data[i];
        }
        s1[length + s.length] = '\0';
        return s1;
    }
    void clear()
    {
        length = 0;
        memset(data, 0, sizeof(data));
    }
    void destroy()
    {
        length = 0;
        memset(data, 0, sizeof(data));
    }
    void print()
    {
        for (int i = 0; i < length; i++)
        {
            cout << data[i];
        }
        cout << endl;
    }
    // ����=��
    Str &operator=(const char *&s)
    {
        if (strlen(s) > N)
        {
            cout << "�ַ������ȳ�������" << endl;
            return *this;
        }
        length = strlen(s);
        for (int i = 0; i < length; i++)
        {
            data[i] = s[i];
        }
        return *this;
    }
};
int main()
{
    Str s1 = "hello", s2 = "world";
    cout << "s1 = " << s1.data << endl;
    cout << "s2 = " << s2.data << endl;
    cout << "s1 == s2 ? " << (s1.compare(s2) == 0) << endl;
    cout << "s1 < s2 ? " << (s1.compare(s2) == -1) << endl;
    cout << "s1 > s2 ? " << (s1.compare(s2) == 1) << endl;
    cout << "s1.len() = " << s1.len() << endl;
    cout << "s2.len() = " << s2.len() << endl;
    cout << "s1.subString(1, 3) = " << s1.subString(1, 3) << endl;
    cout << "s1.concat(s2) = " << s1.concat(s2) << endl;
    Str s3 = "ell";
    cout << "s3 in s1 ? " << s1.index(s3) << endl;
    s3 = "wor";
    cout << "s3 in s1 ? " << s1.index(s3) << endl;
    cout << "s1: ";
    s1.print();
    cout << "s2: ";
    s2.print();
    s1.destroy();
    s2.destroy();
    system("pause");
    return 0;
}