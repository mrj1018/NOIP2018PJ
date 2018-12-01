#include <cstdio>
#include <algorithm>
#define MAXN 5005
#define MAXT 5000005
#define INF 100000000
using namespace std;

int a[MAXN]; //a���μ�¼��������������ʱ��

int main(void){
    int n,m;
    scanf("%d%d",&n,&m);
    if (m<=1){ //ÿ��ʱ�̶����Է���������ȴ� 
        printf("0\n");
        return 0;
    }
    for (int i=0;i<n;i++)
        scanf("%d",a+i);
    sort(a,a+n); //��ʱ���������
    int ans=0;
    int last_bus_time=a[0]; //��¼��ǰ�����һ�೵��ʱ�� 
    for (int i=0;i<n;i++){
    	if (a[i]>=last_bus_time+m) //�ٷ�һ�೵�Դ��ص�i���� 
    		last_bus_time=a[i];
    	if (a[i]>last_bus_time)
    		last_bus_time+=m;
        ans+=(last_bus_time-a[i]); //����i���˵ȴ���ʱ���ۼ������ 
    }
    printf("%d\n",ans);
    return 0;
}
