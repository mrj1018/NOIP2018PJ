#include <cstdio>
#include <algorithm>
#define MAXN 5005
#define MAXT 5000005
#define INF 100000000
using namespace std;

int a[MAXN],temp_a[MAXN]; //a���μ�¼��������������ʱ��, temp_a������ʱ�洢 
int cnt[MAXT],scnt[MAXT]; //cnt[i]Ϊʱ��i������������,scnt[i]Ϊ1~iʱ�������������� 
long long wcnt[MAXT]; //���ڼ���ȴ�ʱ�� 
int f[MAXT];
//f[i]��ʾ�����װ೵��iʱ�̷�����i+1ʱ�̼��Ժ������˵���С�ȴ�ʱ�� 

int main(void){
    int n,m;
    int max_time,min_time; //�������������ĵ���ʱ�� 
    scanf("%d%d",&n,&m);
    if (m<=1){ //ÿ��ʱ�̶����Է���������ȴ� 
        printf("0\n");
        return 0;
    }
    for (int i=0;i<n;i++){
        scanf("%d",a+i);
        a[i]++; //��ʱ������ƽ��һ����λ�����ڴ��� 
	}
    sort(a,a+n); //��ʱ��������� 
    int m_times_2=m*2; //2m
    for (int i=0;i<n;i++){
        int lst_pos=lower_bound(a,a+n,a[i])-1-a; //�ҵ���һ�����˵�ʱ�� 
        if (a[i]>a[lst_pos]+m_times_2)
            //��һ�����˵�ʱ����2m����λʱ��֮ǰ�����԰���֮���ʱ����ǰƽ�� 
            temp_a[i]=temp_a[lst_pos]+m_times_2;
        else
            //������ʱ�̵ļ�಻��2m
            //���ּ�� 
            temp_a[i]=temp_a[lst_pos]+(a[i]-a[lst_pos]);
    }
    
    //��������ʱ�临�Ƶ�ԭλ 
    for (int i=0;i<n;i++)
        a[i]=temp_a[i];
    
    max_time=0,min_time=INF;
    for (int i=0;i<n;i++){
        //����min_time��max_time 
        if (a[i]<min_time)
           min_time=a[i];
        if (a[i]>max_time)
           max_time=a[i];
        cnt[a[i]]++; //cnt��¼ÿһ��ʱ�̵����� 
    }
    
    int time_end=max_time+m_times_2; //time_end��Ϊmax_time+m_times_2,����������Ҫ��������ʱ�� 
    
    //scnt�����¼cnt�����ǰ׺�ͣ���scnt[i]Ϊ1~iʱ�̵������� 
    for (int i=min_time;i<=time_end;i++)
        scnt[i]=scnt[i-1]+cnt[i];
    
    //wcnt�������ڼ���һ�������ڵ���������Ҫ�ȴ�����ʱ�� 
    for (int i=min_time;i<=time_end;i++)
        wcnt[i]=cnt[i]*(time_end-i);
    for (int i=min_time;i<=time_end;i++){
        wcnt[i]+=wcnt[i-1];
    }
    
    for (int i=max_time;i>=min_time;i--){
        f[i]=INF;
        for (int j=i+m;j<i+m_times_2;j++){
            //��һ�೵������i+m~i+2m���ʱ�䷢��
            int waiting=(wcnt[j-1]-wcnt[i])-(time_end-j)*(scnt[j-1]-scnt[i]);
            //waiting����i+1~j-1���ʱ��������ˣ��ȴ���jʱ�̵��ܵȴ�ʱ��
            if (f[j]+waiting<f[i])
               f[i]=f[j]+waiting;
        }
    }
    
    int ans=INF;
    for (int i=min_time;i<=max_time;i++){
        int tans; //�����װ೵��iʱ�̷���ʱ�Ĵ�
        //tans=1~i-1���˵ȴ��װ೵����Ҫ��ʱ�� + i+1~max_time���˵ȴ���ʱ��(f[i])
        //�������min_time~i-1���ʱ��������ˣ��ȴ���iʱ�̵��ܵȴ�ʱ��
        tans=(wcnt[i-1]-wcnt[min_time-1])-(time_end-i)*(scnt[i-1]-scnt[min_time-1]);
        tans+=f[i];
        if (tans<ans)
            ans=tans;
    }
    printf("%d\n",ans);
    return 0;
}
