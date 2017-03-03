

/****************************************

@_@
Cat Got Bored *_*
#_#
*****************************************/

#include <bits/stdc++.h>


#define loop(i,s,e) for(int i = s;i<=e;i++) //including end point

#define pb(a) push_back(a)

#define sqr(x) ((x)*(x))

#define CIN ios_base::sync_with_stdio(0); cin.tie(0);

#define ll long long

#define ull unsigned long long

#define SZ(a) int(a.size())

#define read() freopen("input.txt", "r", stdin)

#define write() freopen("output.txt", "w", stdout)


#define ms(a,b) memset(a, b, sizeof(a))

#define all(v) v.begin(), v.end()

#define PI acos(-1.0)

#define pf printf

#define sfi(a) scanf("%d",&a);

#define sfii(a,b) scanf("%d %d",&a,&b);

#define sfl(a) scanf("%lld",&a);

#define sfll(a,b) scanf("%lld %lld",&a,&b);

#define mp make_pair

#define paii pair<int, int>

#define padd pair<dd, dd>

#define pall pair<ll, ll>

#define fs first

#define sc second

#define CASE(t) printf("Case %d: ",++t) // t initialized 0

#define INF 1000000000   //10e9

#define EPS 1e-9


using namespace std;
int digital_root[1000009];
ll num_dr[10];//How many digital roots with value i
int main()
{
    int N;

    sfi(N);
    ms(num_dr,0);
    //Lets first find all digital roots of i for i = 1 to N
    //There's a O(1) formula for digital root
    int N_max = 1000005;
    loop(x,1,N_max)   //We need to calculate all digital root up to max possible range as, when in the num_dr[dr*dr2]
    {                 //We would need to calculate DR of dr*dr2 which maybe >N so,if we just run this loop up to N we 'll miss some values
        digital_root[x] = 1 + (x-1)%9 ; //https://en.wikipedia.org/wiki/Digital_root
        //for base b , 9 can be replaced with (b-1)
        if(x<=N)
        num_dr[ digital_root[x]  ]++; //We wont add to counter if x is bigger than N
    }

    //Now we need to find all such triplets (x,y,z) such that
    // z != x*y   but   digital_root(z) = digital_root(digital_root(x)*digital_root(y))

    //Try to understand the statement carefully . It seemed a bit confusing to me first


    /*  "Not long ago Billy came across such a problem, where there were given three natural numbers
     A, B and C from the range [1, N], and it was asked to check whether the equation AB = C
      is correct. Recently Billy studied the concept of a digital root of a number. We should
       remind you that a digital root d(x) of the number x is the sum s(x) of all the digits
        of this number, if s(x) ≤ 9, otherwise it is d(s(x)). For example, a digital root of
         the number 6543 is calculated as follows: d(6543) = d(6 + 5 + 4 + 3) = d(18) = 9.
         Billy has counted that the digital root of a product of numbers is equal to the
        digital root of the product of the factors' digital roots, i.e. d(xy) = d(d(x)d(y)).
      And the following solution to the problem came to his mind: to calculate the digital
    roots and check if this condition is met. However, Billy has doubts that this condition is sufficient."
    */



//So, in brief billy has invented an algorithm he believes that if
//for some triplets (A,B,C) it can be showed that DR(A) = DR(DR(B)*DR(C)) //DR for digital_root()
//Then , A = B*C
//For example ,
// DR(6) = DR(DR(3)*DR(2)) so, 6 = 3*2  -> Billy's algorithm gives correct result
// DR(21) = DR(DR(3)*DR(4))  but, 21 != 3*4  -> Billy's algorithm gives wrong result

//You are asked to find the number of triplets (A,B,C) such that Billy's algorithm gives wrong answer

//Observe , we can easily apply modular property and see that , from definition of digital root (That we used using %)
// If, A = B*C
//Then , A%9 = (B%9*C%9)%9
//But,that's the number of correct ans , we are looking for number of wrong answers
//So,lets calculate number of all ans for which , DR(A) = DR(DR(B)*DR(C)) both correct ans and wrong ans

//This can be easily done
//Lets save number of digital_roots with value i ; i= 1 to 9
//As,we know digital root is bounded function [1 to 9]
//We use counters where we save this information


//Now a bit of combinatorics
//A simple example,
//You have "m" numbers whose digital root is x .You have "n" numbers whose digital root is y .
//and You have "o" numbers whose digital root is DR(x*y) . //and as we know DR(some number) is always >=1 .. <=9
//So,  1=< x <=9   1=< y <=9   1=< DR(x*y) <=9
//(x,y,DR(x*y)) is such a triplet
//How many triplets can be made this way
//for x we have m possibility ,for y we have n possibility ,for DR(x*y) we have o possibility

ll num_all_triplets = 0;
loop(dr,1,9) //DR is in this range
{

    loop(dr2,1,9) // We want to find such pairs x,y -> x*y this forms a valid triplet (x,y,xy)
    {
        num_all_triplets+= num_dr[dr]*num_dr[dr2]*num_dr[  digital_root[dr*dr2]   ];










    }

}

//But now we must subtract all the correct ans
//How can we do that , easy by finding all such triplets
//A = B*C in the range 1 to N
//For example , if we fix N = 5
//such triplets are , (1,1,1) (2,1,2) (4,2,2) (3,1,3) (4,1,4) (5,1,5)
//We can show that , this can be calculated this way ,


 //1)number of X <=N which has factor 1   //2)number of X <=N which has factor 2   //3)number of X <=N which has factor 3 ...... //N)number of X <=N which has factor N

//Why this works ? 1)-> (1,1,1) (2,1,2) (3,1,3) ..... (N,1,N)
//2)-> (2,1,2) (4,2,2) (6,2,3) ..... (N,2,N/2)
//..... This way we get all those triplets we are looking for
//And we number of X<=N with factor i is just floor(N/i)
//For example,1.. N has N numbers with factor 1 , 1.. N has N/2 numbers with factor 2 ...easy to realize

ll num_correct_triplets = 0;
loop(i,1,N)
{
    num_correct_triplets += (N/i) ; //Works same way as floor function
}
ll final_ans = num_all_triplets - num_correct_triplets;

cout<<final_ans<<endl;

    return 0;
}
