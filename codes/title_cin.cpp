#include <iostream>
#include <cstring>
using namespace std;
char title[105];

int main(void){
    int ans=0,length;
    while (cin >> title){ //�������ַ����ɶ���ʱ��ѭ������� 
        length=strlen(title);
        for (int i=0;i<length;i++)
            if (i!=' ' && i!='\n' && i!='\r')
                ans++;
    }
   cout << ans << endl;
    return 0;
}
