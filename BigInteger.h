
//BigInteger header file implementation
//Priyanshi Agrawal


#ifndef BigInteger_H_INCLUDED
#define BigInteger_H_INCLUDED

#include<iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;


#define absBig BigInteger::absBigInteger
#define factBig BigInteger::factBigInteger
#define maxBig BigInteger::maxBigInteger
#define minBig BigInteger::minBigInteger
#define isPaliBig BigInteger::isPaliBigInteger
#define sortBig BigInteger::sortBigInteger
#define powBig BigInteger::powBigInteger
#define to_Big BigInteger::to_BigInteger
#define revBig BigInteger::revBigInteger
#define countBig BigInteger::countBigInteger
#define eraseBig BigInteger::eraseBigInteger

class BigInteger {

    private:
        string str;

    public:

    BigInteger ()
    {
        str = "0";
    }

    BigInteger (string s)
    {
        if(!isInputCorrect(s)) {
            cerr << "Invalid Input.. Please Use Valid BigInteger" << endl;
            exit(0);
        }
        str = s;        
    }

    BigInteger (int n)
    {
        ostringstream convertstr;
        convertstr << n;
        str = convertstr.str();
    }

    BigInteger (long long int n)
    {
        ostringstream convertstr;
        convertstr << n;
        str = convertstr.str();
    }

    BigInteger (const BigInteger &N2)
    {
        if(!isInputCorrect(N2.str)) {
            cerr << "Invalid Input.. Please Use Valid BigInteger" << endl;
            exit(0);
        }
        str = N2.str;
    }

    // Input Validator
    bool isInputCorrect(string s) {
        if(s[0] == '-')
            s.erase(0, 1);
        for(int i = 0; i < s.length(); ++i) {
            if((int)s[i] < 48 || (int)s[i] > 57)
                return false;
        }
        return true;
    }

    friend ostream &operator<<( ostream &output, const BigInteger &N )
    {
         output<<N.str;
         return output;
    }

    friend istream &operator>>( istream  &input, BigInteger &N )
    {
         input >> N.str;
         return input;
    }

    static BigInteger to_BigInteger(string s)
    {
        BigInteger N3;
        N3.str = s;
        return N3;
    }

    static BigInteger to_BigInteger(int n)
    {
        BigInteger N3;
        ostringstream convertstr;
        convertstr << n;
        N3.str = convertstr.str();
        return N3;
    }

    static BigInteger to_BigInteger(long long int n)
    {
        BigInteger N3;
        ostringstream convertstr;
        convertstr << n;
        N3.str = convertstr.str();
        return N3;
    }


    static string removeZero(string str)
    {
        int i = 0, flag = 0;
        if(str[0] == '-')
        {
            flag = 1;
            i++;
        }
        while (str[i] == '0')
           i++;
        if(flag)
            str.erase(1, i);
        else
            str.erase(0, i);
        return str;
    }

    static string add(string s, string s1)
    {
        int carry=0,i,j;
        int sum=0;
        int m=s.length();
        int n=s1.length();
        string y = "";
        if(m == 0 && n == 0)
        {
            y = "0";
        }
        else if(s[0] == '-' && s1[0] == '-')
        {
            y = add(s.erase(0,1), s1.erase(0, 1));
            y = '-' + y;
        }
        else if(s[0] == '-')
        {
            y = subtract(s1, s.erase(0, 1));
        }
        else if(s1[0] == '-')
        {
            y = subtract(s, s1.erase(0, 1));
        }
        else
        {
            vector<int>v;
            for(i=m-1,j=n-1;i>=0||j>=0;i--,j--)
            {
                sum=carry;
                if(i>=0)
                {
                    sum+=s[i]-'0';
                }
                if(j>=0)
                {
                    sum+=s1[j]-'0';
                }
                v.push_back(sum%10);
                carry=sum/10;
            }
            if(carry!=0)
            v.push_back(carry);

            for(i=v.size()-1;i>=0;i--)
                y += (char)(v[i]+48);
        }
        return y;
    }

    static string subtract(string s1,string s2)
    {
        string answer="",ans,temp;
        int carry=0,i,j,k,y=0,flag=0,flag1=0;
        int sum=0;
        if(s1==s2)
        {
            return "0";
        }
        else if(s1[0]=='-' and s2[0]=='-')
        {
            flag1=1;
            s1=s1.substr(1);
            s2=s2.substr(1);
        }
        else if(s1[0]=='-' and s2[0]!='-')
        {
            s1=s1.substr(1);
            answer=add(s1,s2);
            answer='-'+answer;
            return answer;
        }
        else if(s1[0]!='-' and s2[0]=='-')
        {
            s2=s2.substr(1);
            answer=add(s1,s2);
            return answer;
        }
        ans=maxCompare(s1,s2);
        if(ans==s2)
        {
            temp=s1;
            s1=s2;
            s2=temp;
            flag=1;
        }
        int m=s1.length();
        int n=s2.length();
        if(m>n)
        k=m;
        else
        k=n;
        int A[k+1]={0};
        for(i=m-1,j=n-1;i>=0||j>=0;i--,j--)
        {
            sum=0;
            if(i>=0)
            {
                sum+=s1[i]-'0';
            }
            if(j>=0)
            {
                if(sum<s2[j]-'0'+carry)
                {
                    sum+=10;
                    sum-=s2[j]-'0'+carry;
                    carry=1;
                }
                else
                {
                    sum-=s2[j]-'0'+carry;
                    carry=0;
                }
            }
            if(carry!=0 and j<0)
            {
              if(sum<carry)
              {
                sum+=10;
                sum-=carry;
                carry=1;
              }
              else
              {
                sum-=carry;
                carry=0;
              }
            }
            A[y++]=sum;
            //carry=sum/10;
        }
        for(i=k-1;i>=0;i--)
        {
            answer += (char)(A[i] + 48);
        }
        answer=removeZero(answer);
        if(flag1==1 and flag==0)
        {
            answer='-'+answer;
        }
        else if(flag1==0 and flag==1)
        {
            answer='-'+answer;
        }
        return answer;
    }

    static string multiply(string s, string s1)
    {
        int flag=0;
        int m=s.length();
        int n=s1.length();
        int A[m+n]={0};
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                int mul=(s[i]-'0')*(s1[j]-'0');
                int sum=A[i+j+1]+mul;
                A[i+j]+=sum/10;
                A[i+j+1]=sum % 10;
            }
        }

        string finalanswer = "";
        for(int i=0;i<m+n;i++)
        {
            if(A[i]==0 && flag==0 ){}
                else if(A[i]!=0 )
                    flag=1;

            if(flag==1)
                finalanswer += (char)(A[i]+48);
        }
        if(finalanswer.length() == 0)
            finalanswer = "0";
        return finalanswer;
    }

    BigInteger operator++()
    {
        string s = "1";
        str = add(this->str,s);
        return *this;
    }

    BigInteger operator--()
    {
        string s = "1";
        str = subtract(this->str,s);
        return *this;
    }

    BigInteger operator++(int)
    {
        BigInteger N3;
        N3.str = this->str;
        string s = "1";
        str = add(this->str,s);
        return N3;
    }

    BigInteger operator--(int)
    {
        BigInteger N3;
        N3.str = this->str;
        string s = "1";
        str = subtract(this->str,s);
        return N3;
    }

    BigInteger operator + (BigInteger const &N2)
    {
        BigInteger N3;
        string s = str;
	    string s1 = N2.str;
        N3.str = add(s,s1);
        return N3;
    }

    BigInteger operator - (BigInteger const &N2)
    {
        BigInteger N3;
        string s = str;
	    string s1 = N2.str;
        N3.str = subtract(s,s1);
        return N3;
    }

    BigInteger operator * (BigInteger const &N2)
    {
        BigInteger N3;
        string s = str;
	    string s1 = N2.str;
        N3.str = multiply(s,s1);
        return N3;
    }

    BigInteger operator / (BigInteger const &N2)
    {
        BigInteger N3;
        string s1 = str;
	    string s2 = N2.str;
        stringstream convertnum(s2);
        long long int div = 0;
        convertnum>>div;
        N3.str = division(s1,div);
        return N3;
    }

    bool operator == (BigInteger const &N2)
    {
        return this->str == N2.str;
    }

    bool operator != (BigInteger const &N2)
    {
        return this->str != N2.str;
    }

    BigInteger& operator += (BigInteger N2)
    {
        this->str = add(this->str,N2.str);
        return *this;
    }

    BigInteger& operator -= (BigInteger N2)
    {
        this->str = subtract(this->str,N2.str);
        return *this;
    }

    BigInteger& operator *= (BigInteger N2)
    {
        this->str = multiply(this->str,N2.str);
        return *this;
    }

    BigInteger& operator /= (BigInteger N2)
    {
        string s2 = N2.str;
        stringstream convertnum(s2);
        long long int div = 0;
        convertnum>>div;
        this->str = division(this->str,div);
        return *this;
    }

    friend BigInteger operator +(BigInteger &N1,int num)
    {
        BigInteger N3;
        ostringstream convertstr;
        convertstr << num;
        N3.str = convertstr.str();
        N3.str = add(N1.str,N3.str);
        return N3;
    }

    friend BigInteger operator -(BigInteger &N1,int num)
    {
        BigInteger N3;
        ostringstream convertstr;
        convertstr << num;
        N3.str = convertstr.str();
        N3.str = subtract(N1.str,N3.str);
        return N3;
    }

    friend BigInteger operator *(BigInteger &N1,int num)
    {
        BigInteger N3;
        ostringstream convertstr;
        convertstr << num;
        N3.str = convertstr.str();
        N3.str = multiply(N1.str,N3.str);
        return N3;
    }

    friend BigInteger operator /(BigInteger &N1,int num)
    {
        BigInteger N3;
        N3.str = division(N1.str,(long long int)num);
        return N3;
    }

    friend BigInteger operator +(int num, BigInteger &N1)
    {
        BigInteger N3;
        ostringstream convertstr;
        convertstr << num;
        N3.str = convertstr.str();
        N3.str = add(N1.str,N3.str);
        return N3;
    }

    friend BigInteger operator -(int num, BigInteger &N1)
    {
        BigInteger N3;
        ostringstream convertstr;
        convertstr << num;
        N3.str = convertstr.str();
        N3.str = subtract(N3.str,N1.str);
        return N3;
    }

    friend BigInteger operator *(int num, BigInteger &N1)
    {
        BigInteger N3;
        ostringstream convertstr;
        convertstr << num;
        N3.str = convertstr.str();
        N3.str = multiply(N1.str,N3.str);
        return N3;
    }

    friend BigInteger operator /(int num, BigInteger &N1)
    {
        BigInteger N3;
        ostringstream convertstr;
        convertstr << num;
        N3.str = convertstr.str();
        string s2 = N1.str;
        stringstream convertnum(s2);
        long long int div = 0;
        convertnum>>div;
        N3.str = division(N3.str,div);
        return N3;
    }

    static string division(string s1, long long int div)
    {
        string result;
        int index = 0;
        long long int temp = s1[index] - '0';
        while (temp < div)
        {
            temp = temp*10 + (s1[++index] - '0');

            if(index >= s1.length())
                break;
        }


        while (s1.length() > index) {
            result += (temp / div) + '0';
            temp = (temp % div)*10 + s1[++index] - '0';
        }

        if (result.length() == 0)
            return "0";

        return result;
    }

    static string division(string s1, int div)
    {
        string result;
        int index = 0;
        int temp = s1[index] - '0';
        while (temp < div)
        {
            temp = temp*10 + (s1[++index] - '0');

            if(index >= s1.length())
                break;
        }


        while (s1.length() > index) {
            result += (temp / div) + '0';
            temp = (temp % div)*10 + s1[++index] - '0';
        }

        if (result.length() == 0)
            return "0";

        return result;
    }

    static string power(string str1, string str2) {
    if(str2 == "0") {
        return "1";
    } else if(str1 == "0") {
        if(str2[0] == '-')
            return to_string((long long int)std::pow(0, -5));
        return "0";
    } else if(str1[0] == '-' && str2[0] == '-') {
        if(str1 == "-1" && str2 == "-1") {
            return "-1";
        } else if(str1 == "-1") {
            if((((int)str2[str2.length()-1])-48) & 1) {                
                return "-1";
            } else {
                return "1";
            }
        } else {
            return "0";
        }
    } else if(str1[0] == '-') {
        if((((int)str2[str2.length()-1])-48) & 1)
            return '-' + power(str1.erase(0, 1), str2);
        return power(str1.erase(0, 1), str2);
    } else if(str2[0] == '-') {
        if(str1 == "1") {
            return str1;
        } else {
            return "0";
        }
    } else {
        string init_str1 = str1;
        while(str2 != "1") {
            str1 = multiply(str1, init_str1);
            str2 = subtract(str2, "1");
        }
        return str1;
    }
}

    static BigInteger powBigInteger(string str1, string str2)
    {
        BigInteger temp;
        temp.str = power(str1, str2);
        return temp;
    }
    static BigInteger powBigInteger(BigInteger &n1, string str2)
    {
        BigInteger temp;
        temp.str = power(n1.str, str2);
        return temp;
    }
    static BigInteger powBigInteger(string str1, BigInteger &n2)
    {
        BigInteger temp;
        temp.str = power(str1, n2.str);
        return temp;
    }
    static BigInteger powBigInteger(BigInteger &n1, BigInteger &n2)
    {
        BigInteger temp;
        temp.str = power(n1.str, n2.str);
        return temp;
    }
    static BigInteger powBigInteger(int n1, int n2)
    {
        BigInteger temp;
        temp.str = power(to_string(n1), to_string(n2));
        return temp;
    }
    static BigInteger powBigInteger(long int n1, long int n2)
    {
        BigInteger temp;
        temp.str = power(to_string(n1), to_string(n2));
        return temp;
    }
    static BigInteger powBigInteger(long long int n1, long long int n2)
    {
        BigInteger temp;
        temp.str = power(to_string(n1), to_string(n2));
        return temp;
    }

    static string factorial(int n)
    {
        int i=2;
        int j=0;
        int len=1;
        int A[100000]={0};
         A[0]=1;
        int num=0;
        while(i<=n)
        {
            j=0;
            num=0;
            while(j<len)
            {
                A[j]=A[j]*i;
                A[j]=A[j]+num;
                num=A[j]/10;
                A[j]=A[j]%10;
                j++;
            }
            while(num!=0)
            {
                A[len]=num%10;
                num=num/10;
                len++;
            }
            i++;
        }
        len--;
        string y = "";
        while(len>=0)
        {
            y += (char)(A[len]  + '0');
            len=len-1;
        }
        return y;
    }

    static BigInteger factBigInteger(int n)
    {
        BigInteger N3;
        N3.str = factorial(n);
        return N3;
    }

    static BigInteger factBigInteger(BigInteger N1)
    {
        BigInteger N3;
        string s = N1.str;
        stringstream convertnum(s);
        int n = 0;
        convertnum>>n;
        N3.str = factorial(n);
        return N3;
    }

    static BigInteger factBigInteger(string s)
    {
        BigInteger N3;
        stringstream convertnum(s);
        int n = 0;
        convertnum>>n;
        N3.str = factorial(n);
        return N3;
    }

    static string maxCompare(string s1,string s2)
    {
        string answer="";
        int i;
        if(s1[0]=='-' and s2[0]!='-')
        {
            return s2;
        }
        else if(s1[0]!='-' and s2[0]=='-')
        {
            return s1;
        }
        else if(s1[0]!='-' and s2[0]!='-' and s1.length()>s2.length())
        {
            return s1;
        }
        else if(s1[0]!='-' and s2[0]!='-' and s2.length()>s1.length())
        {
            return s2;
        }
        else if(s1[0]=='-' and s2[0]=='-' and s1.length()>s2.length())
        {
            return s2;
        }
        else if(s1[0]=='-' and s2[0]=='-' and s2.length()>s1.length())
        {
            return s1;
        }
        else if(s1[0]!='-' and s2[0]!='-' and s2.length()==s1.length())
        {
            for(i=0;i<s1.length();i++)
            {
                if(s1[i]-'0'<s2[i]-'0')
                {
                    return s2;
                }
                else if(s1[i]==s2[i])
                {
                    continue;
                }
                else if(s1[i]-'0'>s2[i]-'0')
                {
                    return s1;
                }
            }
        }
        else if(s1[0]=='-' and s2[0]=='-' and s2.length()==s1.length())
        {
            for(i=0;i<s1.length();i++)
            {
                if(s1[i]-'0'<s2[i]-'0')
                {
                    return s1;
                }
                else if(s1[i]==s2[i])
                {
                    continue;
                }
                else if(s1[i]-'0'>s2[i]-'0')
                {
                    return s2;
                }
            }
        }
    }

    static string minCompare(string s1,string s2)
    {
        string ans;
        ans=maxCompare(s1,s2);
        if(ans==s1)
        {
            return s2;
        }
            return s1;
    }

    static BigInteger maxBigInteger(BigInteger N1, BigInteger N2)
    {
        string s1,s2,ans;
        s1 = N1.str;
        s2 = N2.str;

        ans=maxCompare(s1,s2);

        if(N1.str == ans)
            return N1;
        else
            return N2;

    }


    static BigInteger minBigInteger(BigInteger N1, BigInteger N2)
    {
        string s1,s2,ans;
        s1 = N1.str;
        s2 = N2.str;

        ans=minCompare(s1,s2);

        if(N1.str == ans)
            return N1;
        else
            return N2;

    }

    static BigInteger absBigInteger(BigInteger N1)
    {
        string s1 = N1.str;

        if(s1[0]=='-')
            s1=s1.substr(1);

        BigInteger N2(s1);
        return N2;
    }

    static BigInteger revBigInteger(BigInteger N1)
    {
        string s2 = "",s1 = N1.str;
        for(int i= s1.length()-1; i>=0; i--)
            s2 += s1[i];
        BigInteger N2(s2);
        return N2;
    }

    static int countBigInteger(BigInteger N1, int n)
    {
        char c = (char)(n + '0');
        int counti = 0;
        for(int i=0; i< N1.str.length(); i++)
        {
            if(N1.str[i] == c)
                counti++;
        }
        return counti;
    }

    static BigInteger eraseBigInteger(BigInteger N1, int n)
    {
        char c = (char)(n + '0');
        string s2 = "";
        int counti = 0;
        for(int i=0; i< N1.str.length(); i++)
        {
            if(N1.str[i] != c)
                s2 += N1.str[i];
        }
        s2 = removeZero(s2);
        if(s2 == "" or s2 == "-")
        {
            BigInteger N2(0);
            return N2;
        }
        else
        {
            BigInteger N2(s2);
            return N2;
        }
    }

    static bool isPaliBigInteger(BigInteger N1)
    {
        string s1 = N1.str;
        int i = 0, j = s1.length()-1;
        if(s1[0] == '-')
            i++;
        while(i<j)
        {
            if(s1[i] != s1[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    static BigInteger sortBigInteger(BigInteger N1)
    {
        string s1 = N1.str;
        int flag = 0;
        if(s1[0] == '-')
        {
            flag = 1;
            s1.erase(0,1);
        }

        sort(s1.begin(), s1.end());

        s1 = removeZero(s1);

        if(flag)
            s1 = '-' + s1;

        if(s1 == "" or s1 == "-")
        {
            BigInteger N2(0);
            return N2;
        }
        BigInteger N2(s1);
        return N2;
    }
};

#endif // BigInteger_H_INCLUDED