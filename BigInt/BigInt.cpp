#include <iostream>
#include <string>
#include <exception>
using namespace std;


class BigInt {
private:
    string number;

    void EqualSize(string& s1, string& s2)
    {
        int l1 = s1.size();
        int l2 = s2.size();

        if (l1 > l2)
            for (int i = 0; i < l1 - l2; i++)
                s2.insert(0, "0");

        if (l2 > l1)
            for (int i = 0; i < l2 - l1; i++)
                s1.insert(0, "0");
    }
    void RemoveLeadingZeros(string& str)
    {
        bool NegativeNum = (str[0] == '-');
        if (NegativeNum)
            str.erase(0, 1);  //remove the negative sign temporarily and will be added after Subtract if the number is negative

        int i = 0;
        while (i < str.size() && str[i] == '0')  //skip all zeros
            i++;

        str.erase(0, i);   //remove all leading zeros after skipping

        if (str.empty())  //if str is empty after removing leading zeros, set it to "0"
            str = "0";

        if (NegativeNum && str != "0")  //reinsert the negative sign if it was there originally
            str = '-' + str;
    }
    bool Validate(const string& s)
    {
        if (s.empty())
        {
            throw invalid_argument("Empty input not allowed");
        }
        if (s[0] == '-' && s.size() == 1)
        {
            throw invalid_argument("Invalid input, alone negative sign not allowed");
        }
        if ((s[0] == '-' && s[1] == '0') && s.size() == 2)
        {
            throw invalid_argument("Invalid input, it can't be like this -0");
        }

        int sign = s[0] == '-';
        if (sign)
            sign = 1;
        for (int i = sign; i < s.size(); i++) //-123
        {
            if (!isdigit(s[i]))
            {
                throw invalid_argument("Invalid input,non numeric characters not allowed");
            }
        }
        return true;
    }
    string AddNumber(string s1, string s2)
    {
        EqualSize(s1, s2);
        string result = "";
        int reminder = 0;

        for (int i = s1.size() - 1; i >= 0; i--)  //from right to left
        {
            int c1 = s1[i] - '0';
            int c2 = s2[i] - '0';

            int total = c1 + c2 + reminder;
            reminder = total / 10;
            char digit = total % 10 + '0';   //modulo to extract the result and get the reminder
            
            result.insert(result.begin(), digit);
        }

        if (reminder == 1)  //if there's any reminder left, add it
        {
            result.insert(0, "1");
        }

        RemoveLeadingZeros(result);
        return result;
    }
    string Subtract(string s1, string s2)
    {
        EqualSize(s1, s2);
        bool NegativeMark = false;

        if (s1 < s2)   //if the first number is smaller, swap them and mark the result as negative
        {
            swap(s1, s2);
            NegativeMark = true;
        }

        string result = "";
        int rest = 0;

        for (int i = s1.size() - 1; i >= 0; i--)
        {
            int c1 = s1[i] - '0';
            int c2 = s2[i] - '0';

            c1 -= rest;    //subtract the rest from next digit in first string s1 that contain c1 as a digit

            if (c1 < c2)    //if the current digit in s1 is smaller than the corresponding digit in s2
            {
                c1 += 10;   //borrow from the next digit
                rest = 1;   //set the borrow flag for the next iteration
            }
            else
            {
                rest = 0;
            }
            char digit = (c1 - c2) + '0';
            result.insert(result.begin(), digit);
        }
        RemoveLeadingZeros(result);

        if (NegativeMark && result != "0")
        {
            result.insert(result.begin(), '-');
        }

        return result;
    }
    string Multiply(string s1, string s2)
    {
        /*
i = 2   *     123      total = 3 * 5 + carry = 15 + 0, carry = 15 / 10 = 1, reminder = 15 % 10 = 5 -> convert to string "5" = partial
        *  x   45      total = 3 * 4 + carry = 12 + 1 = 13, carry = 1, reminder = 3   -> "35"
        * ---------    and we finish the multiplication num1(3) with second string(45) so if there is a carry it will be added to first partial string -> "135"
i = 1   *    "135"     
        * +  "900"     add zero to partial string
        * ---------    total = 2 * 5 + 0 = 10 - > reminder = 0, carry = 1, total = 2 * 4 + 1 = 9 -> reminder = 9, carry 0 , then will add result to partial then increase zeros by 1
i = 0   *   "1035"
        * + "4500"     add another zero to partial string
        * ----------   total = 1 * 5 = 5 -> reminder = 5 , carry = 0, total = 1 * 4 = 4, reminder 4, carry = 0, add result to partial string
i < 0   *   "5535"    
        * +   000"      add another zero then the loop will be terminate and return result.
        */
        string result = "0";
        int zeros = 0;

        for (int i = s1.size() - 1; i >= 0; i--)
        {
            if (s1 == "0" || s2 == "0") return "0";

            int num1 = s1[i] - '0';
            string partial = "";
            int carry = 0;

            for (int j = s2.size() - 1; j >= 0; j--) //123  //45 -> 3 * 25, 2 * 25, 1 * 25
            {
                int num2 = s2[j] - '0';
                int total = (num1 * num2) + carry;         //3 * 5 + 0 = 15 + 0           //3 * 4 + 1 = 12 + 1 = 13
                char reminder = (total % 10) + '0';        //reminder = 15 % 10 = 5       //reminder 13 % 10 = 3
                carry = total / 10;                        //carry = 15 / 10 = 1          //carry = 13 / 10 = 1
                partial = reminder+ partial;               //partial = "5" as a string added to partial string
                                                           //partial = "3" as string added to partial string -> "35"
                
            }
            if (carry)
            {
                partial = char(carry + '0') + partial;       //carry = 1 so will be added as a character to partial string -> "135"
            }
            partial.append(zeros, '0');
            result = AddNumber(result, partial);
            zeros++;
        }
        RemoveLeadingZeros(result);
        return result;
    }
    string Division(string str1, string str2)
    {
        RemoveLeadingZeros(str1);
        RemoveLeadingZeros(str2);
        if (str2 == "0")
            throw runtime_error("Can Not Divide By Zero!");

        int size1 = str1.size();
        int size2 = str2.size();
        if (str1 == "0" || (size1 < size2 || (size1 == size2 && str1 < str2)))
            return "0";

        string divisor = str2;
        string dividend = "";
        string quotient = "";
        string counter;
        string temp;

        //storing digit by digit from str1 in dividend
        for (int index = 0; index < str1.size(); index++)  //str1 = 1009, str2 = 10   dividend = ""
        {
            dividend = dividend + str1[index]; //add first digit, dividend = "1", 1 < 10 so will add the next digit , dividend = "10"
            RemoveLeadingZeros(dividend);

            counter = "0";
            temp = Subtract(dividend, divisor);

            while (temp[0] != '-')
            {
                dividend = temp;
                counter = AddNumber(counter, "1");
                temp = Subtract(dividend, divisor);
           
            }

            quotient = quotient + counter; 
        }

        RemoveLeadingZeros(quotient);
        return quotient;
    }
    string Modulo(string dividend, string divisor)
    {
        string quotient = "0";
        string product = "";
        string mod = "";
        
        RemoveLeadingZeros(dividend);
        RemoveLeadingZeros(divisor);

        if (divisor == "0")
            throw runtime_error("Can't divide by zero!");
        if (dividend == divisor || dividend == "0")
            return "0";

        quotient = Division(dividend, divisor);
        product = Multiply(quotient, divisor);
        mod = Subtract(dividend, product);
 
        RemoveLeadingZeros(mod);
        return mod;
    }
    string Power(string base, string exponent)
    {
        RemoveLeadingZeros(base);
        RemoveLeadingZeros(exponent);

        if (exponent == "0")
            return "1";
        if (exponent == "1")
            return base;
        if (exponent[0] == '-')
            return "0";

        string result = "1"; 

        while (exponent != "0")
        {
            int size = exponent.size() - 1;
            int odd = exponent[size] - '0';
            if (odd % 2 == 1)
            {
                result = Multiply(result, base);
            }
            base = Multiply(base, base);
            exponent = Division(exponent, "2");
        }

        RemoveLeadingZeros(result);
        return result;
    }
    string Increment(string s)
    {
        string result = "";
        int carry = 1;

        for (int i = s.size() - 1; i >= 0; i--)
        {
            int num = s[i] - '0';
            int digit = num + (carry);
            carry = digit / 10;
            char after_increment = (digit % 10) + '0';
            result.insert(result.begin(), after_increment);
        }
        if (carry)
        {
            result.insert(0, "1");
        }
        RemoveLeadingZeros(result);
        return result;
    }
    string Decrement(string s)
    {
        string result = "";
        int borrow = -1;

      for (int i = s.size() - 1; i >= 0; i--)
      {
          int num = s[i] - '0';
          int digit = num + borrow;
          if (digit < 0) 
          {
           digit += 10;  
           borrow = -1;   
          }
          else
          {
            borrow = 0;  
          }
          char after_decrement = digit + '0';
          result.insert(result.begin(), after_decrement);
      }
      RemoveLeadingZeros(result);
      return result;
    }
    int Compare(string s1, string s2)
    {
        RemoveLeadingZeros(s1);
        RemoveLeadingZeros(s2);

        int size1 = s1.size();
        int size2 = s2.size();

        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] > s2[i] || size1 > size2) return 1;
            if (s1[i] < s2[i] || size1 < size2) return -1;
        }
        return 0;  //if two strings are equal
    }

public:
    //Constructors
    BigInt() { number = "0"; }
    BigInt(const char* s)
    {
        if (Validate(s))
        {
            number = s;
        }
        
    }
    BigInt(string s)
    {
        if (Validate(s))
        {
            number = s;
        }
    }
    BigInt(int i)
    {
        number = to_string(i);
    }
    //Arithmetic Operators 
    BigInt operator +(BigInt& i)
    {
        BigInt result;
        string num1 = number;
        string num2 = i.number;
        // Case 1: Both numbers are negative -> (-A) + (-B) = -(A + B)
        if (num1[0] == '-' && num2[0] == '-') //(-5) + (-4) -> 5 + 4 -> 9 = -9
        {
            num1.erase(0, 1);
            num2.erase(0, 1);
            result.number = AddNumber(num1, num2);
            result.number.insert(0, "-");
        }
        else if (num1[0] == '-') // (-5) + (6) -> 5 + 6 -> 5 - 6 -> swap -> 6 - 5 = 1,   //(-5) + (4) -> 5 + 4 -> 5 - 4 -> swap -> 4 - 5 = -1.
        {
            num1.erase(0, 1);
            result.number = Subtract(num2, num1);
        }
        else if (num2[0] == '-')  // (5) + (-6) -> 5 + 6 -> 5 - 6 -> without swap -> -1,  //(5) + (-4) -> 5 + 4 -> 5 - 4 -> 1.
        {
            num2.erase(0, 1);
            result.number = Subtract(num1, num2);
        }
        else
        {
            result.number = AddNumber(num1, num2);
        }

        return result;
    }
    BigInt operator -(BigInt& i) // (8) - (9) no change the sign, (-9) - (8) no change the sign, (-8) - (-9) change sign, (8) - (-9) change sign
    {
        BigInt result;
        string num1 = number;
        string num2 = i.number;

        if (num1[0] == '-' && num2[0] == '-')
        {
            num1.erase(0, 1);
            num2.erase(0, 1);
            result.number = Subtract(num2, num1); //Swap 
        }
        else if (num2[0] == '-')
        {
            num2.erase(0, 1);  
            result.number = AddNumber(num1, num2); 
        }
        else if (num1[0] == '-')
        {
            num1.erase(0, 1);
            result.number = AddNumber(num1, num2);  
            result.number.insert(0, "-");  
        }
        else
        {
            result.number = Subtract(num1, num2);
        }

        return result;
    }
    BigInt operator *(BigInt& i)
    {
        BigInt result;
        string num1 = number;
        string num2 = i.number;

        if (num1 == "0" || num2 == "0") return BigInt("0");

        if (num1[0] == '-' && num2[0] == '-')
        {
            num1.erase(0, 1);
            num2.erase(0, 1);
            result.number = Multiply(num1, num2);
        }
        else if (num1[0] == '-')
        {
            num1.erase(0, 1);
            result.number = Multiply(num1, num2);
            result.number.insert(0, "-");
        }
        else if (num2[0] == '-')
        {
            num2.erase(0, 1);
            result.number = Multiply(num1, num2);
            result.number.insert(0, "-");
        }
        else
        {
            result.number = Multiply(num1, num2);
        }
        return result;
    }
    BigInt operator /(BigInt& i)
    {
        BigInt result;
        string num1 = number;
        string num2 = i.number;

        if (num1[0] == '-' && num2[0] == '-')
        {
            num1.erase(0, 1);
            num2.erase(0, 1);
            result.number = Division(num1, num2);
        }
        else if (num1[0] == '-')
        {
            num1.erase(0, 1);
            result.number = Division(num1, num2);
            result.number.insert(0, "-");
        }
        else if (num2[0] == '-')
        {
            num2.erase(0, 1);
            result.number = Division(num1, num2);
            result.number.insert(0, "-");
        }
        else
        {
            result.number = Division(num1, num2);
        }
        return result;
    }
    BigInt operator %(BigInt& i)
    {
        BigInt result;
        string num1 = number;
        string num2 = i.number;

        if (num1[0] == '-' && num2[0] == '-')
        {
            num1.erase(0, 1);
            num2.erase(0, 1);
            result.number = Modulo(num1, num2);
        }
        else if (num1[0] == '-')
        {
            num1.erase(0, 1);
            result.number = Modulo(num1, num2);
        }
        else if (num2[0] == '-') 
        {
            num2.erase(0, 1);
            result.number = Modulo(num1, num2);
        }
        else
        {
            result.number = Modulo(num1, num2);
        }
        return result;

    }
    BigInt operator ^(BigInt& i)
    {
        BigInt result;
        string num1 = number;
        string num2 = i.number;

        RemoveLeadingZeros(num1);
        RemoveLeadingZeros(num2);


        result.number = Power(num1, num2);
        return result;
    }
    BigInt operator++(int)  //postfix increment return the old value first then increment
    {
        BigInt temp = *this;
        string negative = number;

        if (number[0] == '-')
        {
            negative.erase(0, 1);
            negative = Decrement(negative);
            number = '-' + negative;
        }
        else
        {
            number = Increment(number);
        }
        RemoveLeadingZeros(temp.number);
        return temp;
    }
    BigInt operator--(int)
    {

        BigInt temp = *this;
        string negative = number;

        if (number[0] == '-')
        {
            negative.erase(0, 1);
            negative = Increment(negative);
            number = '-' + negative;
        }
        else
        {
            number = Decrement(number);
        }
        RemoveLeadingZeros(temp.number);
        return temp;
    }
    //Relational operators
    bool operator ==(const BigInt& i)
    {
        string num1 = number;
        string num2 = i.number;

        RemoveLeadingZeros(num1);
        RemoveLeadingZeros(num2);

        return Compare(num1, num2) == 0;
    }
    bool operator >( BigInt& i)
    {
        string num1 = number;
        string num2 = i.number;
        RemoveLeadingZeros(num1);
        RemoveLeadingZeros(num2);

        if (num1[0] == '-' && num2[0] != '-') {
            return false; 
        }
        if (num1[0] != '-' && num2[0] == '-') {
            return true; 
        }
        if (num1[0] == '-' && num2[0] == '-') {
            num1.erase(0, 1); 
            num2.erase(0, 1);
            return Compare(num1, num2) == -1;
        }
        if (num1.size() > num2.size() && (num1[0] != '-' && num2[0] != '-'))
        {
            return Compare(num1, num2) == 1;
        }
        else if(num1.size() < num2.size() && (num1[0] != '-' && num2[0] != '-'))
        {
            return Compare(num1, num2) == -1;
        }
        return Compare(num1, num2) == 1;
    }
    bool operator <(const BigInt& i)
    {
        string num1 = number;
        string num2 = i.number;
        RemoveLeadingZeros(num1);
        RemoveLeadingZeros(num2);

        if (num1[0] == '-' && num2[0] != '-')
        {
            return true;
        }
        if (num1[0] != '-' && num2[0] == '-')
        {
            return false;
        }
        if (num1[0] == '-' && num2[0] == '-')
        {
            num1.erase(0, 1);
            num2.erase(0, 1);
            return Compare(num1, num2) == 1;
        }
        if (num1.size() > num2.size() && (num1[0] != '-' && num2[0] != '-'))
        {
            return Compare(num1, num2) == -1;
        }
        else if (num1.size() < num2.size() && (num1[0] != '-' && num2[0] != '-'))
        {
            return Compare(num1, num2) == 1;
        }

        return Compare(num1, num2) == -1;
    }
    bool operator !=( BigInt& i)
    {
        RemoveLeadingZeros(number);
        RemoveLeadingZeros(i.number);

        return !(*this == i);  //this pointer points to the first/current number and i refere to the second number
    }
    bool operator >=( BigInt& i)
    {
        RemoveLeadingZeros(number);
        RemoveLeadingZeros(i.number);

        return (*this > i) || (*this == i);
    }
    bool operator <=( BigInt& i)
    {
        RemoveLeadingZeros(number);
        RemoveLeadingZeros(i.number);

        return (*this < i) || (*this == i);
    }
    //Logical operators: zeros represent false , non-zeros represent true
    bool operator &&(BigInt& i)
    {
        RemoveLeadingZeros(number);
        RemoveLeadingZeros(i.number);

        if (number != "0" && i.number != "0")
            return true;
        else
            return false;
    }
    bool operator ||(BigInt& i)
    {
        RemoveLeadingZeros(number);
        RemoveLeadingZeros(i.number);

        if (number != "0" || i.number != "0")
            return true;
        else
            return false;
    }
    bool operator !()
    {
        RemoveLeadingZeros(number);
        if (number == "0")
            return true;    //it should be return false if number = 0 but to negate ! this condition we must return true
        else
            return false;
    }
    //Assignment operators
    BigInt operator =(const BigInt& i)
    {
        number = i.number;
        RemoveLeadingZeros(number);
        return *this;
    }
    BigInt operator +=(BigInt& i)
    {
        string num1 = number;
        string num2 = i.number;

        if (num1[0] == '-' && num2[0] == '-') 
        {
            num1.erase(0, 1);
            num2.erase(0, 1);
            number = AddNumber(num1, num2);
            number.insert(0, "-");
        }
        else if (num1[0] == '-') 
        {
            num1.erase(0, 1);
            number = Subtract(num2, num1);
        }
        else if (num2[0] == '-') 
        {
            num2.erase(0, 1);
            number = Subtract(num1, num2);
        }
        else
        {
            number = AddNumber(num1, num2);
        }
        return *this;
    }
    BigInt operator -=(BigInt& i)
    {
        string num1 = number;
        string num2 = i.number;

        if (num1[0] == '-' && num2[0] == '-')
        {
            num1.erase(0, 1);
            num2.erase(0, 1);
            number = Subtract(num2, num1); //Swap 
        }
        else if (num2[0] == '-')
        {
            num2.erase(0, 1);
            number = AddNumber(num1, num2);
        }
        else if (num1[0] == '-')
        {
            num1.erase(0, 1);
            number = AddNumber(num1, num2);
            number.insert(0, "-");
        }
        else
        {
            number = Subtract(num1, num2);
        }

        return *this;
    }
    BigInt operator *=(BigInt& i)
    {
        string num1 = number;
        string num2 = i.number;

        if (num1 == "0" || num2 == "0")
        {
            number = "0";
        }
        if (num1[0] == '-' && num2[0] == '-')
        {
            num1.erase(0, 1);
            num2.erase(0, 1);
            number = Multiply(num1, num2);
        }
        else if (num1[0] == '-')
        {
            num1.erase(0, 1);
            number = Multiply(num1, num2);
            number.insert(0, "-");
        }
        else if (num2[0] == '-')
        {
            num2.erase(0, 1);
            number = Multiply(num1, num2);
            number.insert(0, "-");
        }
        else
        {
            number = Multiply(num1, num2);
        }
        return *this;
    }
    BigInt operator /=(BigInt& i)
    {
        string num1 = number;
        string num2 = i.number;

        if (num1[0] == '-' && num2[0] == '-')
        {
            num1.erase(0, 1);
            num2.erase(0, 1);
            number = Division(num1, num2);
        }
        else if (num1[0] == '-')
        {
            num1.erase(0, 1);
            number = Division(num1, num2);
            number.insert(0, "-");
        }
        else if (num2[0] == '-')
        {
            num2.erase(0, 1);
            number = Division(num1, num2);
            number.insert(0, "-");
        }
        else
        {
            number = Division(num1, num2);
        }
        return *this;
    }
    //cout, cin classes
    friend ostream& operator <<(ostream& out, BigInt i)
    {
        out << i.number;
        return out;
    }
    friend istream& operator >>(istream& input, BigInt i)
    {
        input >> i.number;
        return input;
    }

    //function to access private member(number)
    string GetNumber()
    {
        return number;
    }
    bool GetValid(string s)
    {
        return Validate(s);
    }
};
