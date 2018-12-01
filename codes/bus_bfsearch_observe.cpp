#include <cstdio>
#include <algorithm>
#define MAXN 505
#define INF 100000000
using namespace std;

int a[MAXN],temp_a[MAXN]; //a���μ�¼��������������ʱ��, temp_a���ڽ�ʱ�����ѹ�� 
int max_time; //max_time��¼���ʱ��
int n,m;

int dfs(int now_time,int last_sent);

int main(void){
    scanf("%d%d",&n,&m);
    if (m<=1){ //ÿ��ʱ�̶����Է���������ȴ� 
        printf("0\n");
        return 0;
    }
    for (int i=1;i<=n;i++)
        scanf("%d",a+i);
    sort(a+1,a+1+n); //��ʱ���������
    
    int m_times_2=m*2; //2m
    for (int i=1;i<=n;i++){
        int lst_pos=lower_bound(a+1,a+n+1,a[i])-1-a; //�ҵ���һ�����˵�ʱ�� 
        if (a[i]>a[lst_pos]+m_times_2)
            //��һ�����˵�ʱ����2m����λʱ��֮ǰ�����԰���֮���ʱ����ǰƽ�� 
            temp_a[i]=temp_a[lst_pos]+m_times_2;
        else
            //������ʱ�̵ļ�಻��2m
            //���ּ�� 
            temp_a[i]=temp_a[lst_pos]+(a[i]-a[lst_pos]);
    }
    
    //��������ʱ�临�Ƶ�ԭλ 
    for (int i=1;i<=n;i++)
        a[i]=temp_a[i];
    
    max_time=a[n]+m_times_2;
    
    int ans=INF;
    for (int i=0;i<m;i++){
        int tans=dfs(a[1]+i,0); //ö���װ೵ʱ��,��¼��
        if (tans<ans)
            ans=tans;
    }
    printf("%d\n",ans);
    return 0;
}

int dfs(int now_time,int last_sent){
    printf("dfs(%d,%d)\n",now_time,last_sent);
    //��now_timeʱ�̷���, ����last_sent+1~n��Щ�˵���̵ȴ�ʱ��֮�� 
    //Ҫ����now_timeʱ�̷���
    int now_ans=0,now_sent=last_sent; //now_ans��ʾ�ȴ����˳����˵ĵȴ�ʱ��֮�� 
    //�ѵȴ���һ�˳����˵ĵȴ�ʱ���ۼ������
    while (now_sent<n && a[now_sent+1]<=now_time){
        //��ʾnow_sent+1����˿��Գ������˳� 
        now_sent++;
        now_ans+=(now_time-a[now_sent]);
    }
    if (now_sent==n){
        //˵�����е��˶��Ѿ��г��ɳ�
        return now_ans;
    }
    //ö����һ�೵��ʱ��
    int m_times_2=m*2;
    int return_ans=INF; //�洢��Ҫ���ص���С�𰸣���last_sent+1��n��Щ�˵���С�ȴ�ʱ�� 
    for (int i=m;i<m_times_2;i++){
    	//�������೵��ʱ������С��m,������2m 
        int tans=dfs(now_time+i,now_sent); //tans��ʾ�������(now_sent+1~n)�ȳ�����Сʱ�� 
        if (tans+now_ans<return_ans)
            return_ans=tans+now_ans;
    }
    return return_ans;
}