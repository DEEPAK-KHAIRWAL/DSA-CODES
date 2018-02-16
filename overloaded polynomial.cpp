#include<iostream>
using namespace std;
class term
{
    public:
    int coeff;
    int expo;  
    friend istream& operator>>(istream&,term&);
    friend ostream& operator<<(ostream&,term&);
};
class poly
{
    int num;
    term *terms;
    public:
    //default constructor
    // allocate memory for 20 terms
    poly();
    //parameterized constructor
    //allocate memory as per user input
    poly(int);
    poly(poly&);
    poly operator+(poly&);
    poly operator++();
    poly operator++(int);  
    //Assignment operator overloading
    poly& operator=(const poly&);
    friend istream& operator>>(istream&,poly&);
    friend ostream& operator<<(ostream&,poly&);
};
1

poly::poly()

2

{

3

    num=0;

4

    terms=new term[10];

5

}

6

poly::poly(int a)

7

{

8

    num=a;

9

    terms=new term[10];

10

}

11

poly::poly(poly &p)

12

{

13

    num=p.num;

14

    terms=new term[10];

15

}

16

poly poly::operator+(poly& p)

17

{

18

    poly temp;

19

    int i,j,k=0;

20

    int done =0;

21

    term *point,*p2,*p3;

22

    p2=p.terms;

23

    p3=terms;

24

    point=temp.terms;

25

 

26

    while(done!=1)

27

    {

28

        if((p.terms)->expo>terms->expo)

29

        {

30

            temp.terms->expo=p.terms->expo;

31

            temp.terms->coeff=p.terms->coeff;

32

            p.terms++;

33

 

34

        }

35

 

36

        else if((p.terms)->expo<terms->expo)

37

        {

38

            temp.terms->expo=terms->expo;

39

            temp.terms->coeff=terms->coeff;

40

            terms++;

41

 

42

        }

43

        else

44

        {

45

            temp.terms->expo=terms->expo;

46

            temp.terms->coeff=p.terms->coeff+terms->coeff;

47

            p.terms++;

48

            terms++;

49

        }

50

    if(p.terms->coeff==0 && p.terms->expo==0)

51

    {

52

    if(terms->coeff==0 && terms->expo==0)

53

    {

54

    done=1;

55

    }

56

    }

57

        (temp.terms)++;

58

        k++;

59

    }

60

    temp.num=k;

61

    temp.terms->coeff=0;

62

    temp.terms->expo=0;

63

    temp.terms=point;

64

    p.terms=p2;

65

    terms=p3;

66

    return temp;

67

}

68

poly poly::operator      ++  ()

69

{

70

    poly temp;

71

    term *point,*p2,*p3;

72

    int d=0;

73

    point=temp.terms;

74

    p2=terms;

75

    temp.terms->coeff=terms->coeff+1;

76

    temp.terms->expo=terms->expo+1;

77

    d++;

78

    temp.terms++;

79

    while(terms->coeff!=0 || terms->expo!=0)

80

    {

81

        temp.terms->coeff=terms->coeff;

82

        temp.terms->expo=terms->expo;

83

        temp.terms++;

84

        d++;

85

        terms++;

86

    }

87

    temp.num=d;

88

    temp.terms->coeff=0;

89

    temp.terms->expo=0;

90

    temp.terms=point;

91

    terms=p2;

92

 

93

    return temp;

94

}

95

poly poly::operator++(int a)

96

{

97

    poly temp;

98

    term *point,*p2,*p3;

99

    int d=0;

100

    point=temp.terms;

101

    p2=terms;

102

    temp.terms->coeff=terms->coeff+1;

103

    temp.terms->expo=terms->expo+1;

104

    d++;

105

    temp.terms++;

106

    while(terms->coeff!=0 || terms->expo!=0)

107

    {

108

        temp.terms->coeff=terms->coeff;

109

        temp.terms->expo=terms->expo;

110

        temp.terms++;

111

        d++;

112

        terms++;

113

    }

114

    temp.num=d;

115

    temp.terms->coeff=0;

116

    temp.terms->expo=0;

117

    temp.terms=point;

118

    terms=p2;

119

 

120

    *this=temp;

121

}

122

poly& poly::operator=(const poly& p)

123

{

124

    num=p.num;

125

    terms=p.terms;

126

}

127

istream& operator>>(istream& b,term& t)

128

{

129

 

130

    b>>t.coeff>>t.expo;

131

    return b;

132

    }

133

ostream& operator<<(ostream& a,term& t)

134

{

135

    a<<t.coeff<<endl<<t.expo;

136

    return a;

137

}

138

istream& operator>>(istream& a,poly& p)

139

{

140

    a>>p.num;

141

    term *point;

142

    point=p.terms;

143

    for(int i=0;i<p.num;i++)

144

    {

145

    a>>*(p.terms);

146

    (p.terms)++;

147

    }

148

    p.terms=point;

149

 

150

 

151

    return a;

152

    }

153

ostream& operator<<(ostream& a,poly& p)

154

{

155

    term *point;

156

    point=p.terms;

157

    for(int i=0;i<p.num;i++)

158

    {

159

    a<<*(p.terms)<<endl;

160

    (p.terms)++;

161

    }

162

    p.terms=point;

163

    return a;

164

}

int main()
{
    poly p1,p2,p3;
    poly p4(5),p5(p4);
    poly p6,p7;
    cin>>p1>>p2;
    p3 = p1+p2;
    cout<<p3;
    p7 = ++p1;
    cout<<p7;
    p2++;
    cout<<p2;
}
