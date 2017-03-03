#include <bits/stdc++.h>

using namespace std;
int server_a_in;
int server_a_out;
int server_b_in;
int server_b_out;

int main()
{

    int n;
    scanf("%d",&n);
    while(n--)
    {
      int a,b,c;
      scanf("%d %d %d",&a,&b,&c);
      if(a==1)
      {
          server_a_in +=b;
          server_a_out+=c;
      }
      else

      {
          server_b_in +=b;
          server_b_out+=c;
      }
    }

    if(server_a_in<server_a_out)
        printf("DEAD\n");
    else printf("LIVE\n");

    if(server_b_in<server_b_out)
        printf("DEAD\n");
    else printf("LIVE\n");

    return 0;
}