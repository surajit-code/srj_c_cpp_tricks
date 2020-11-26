#include <iostream>
#include <bits/stdc++.h>

typedef struct openCloseTermTuplesS {
    char openTerm;
    char closeTerm;
} openCloseTermTuplesT;

void verifyBalancedExpression(std::string input);

int main()
{
    std::string input = "dfdd{dssfd}sdaas";
    verifyBalancedExpression(input);

    input = "sdsd[dsdsds(fddfdf)dsads]sdasd";
    verifyBalancedExpression(input);
    input = "sdsd[dsdsds(fddfdf)dsadssdasd";
    verifyBalancedExpression(input);
    input = "sdsd[dsdsds(fddfdf)dsads}sdasd";
    verifyBalancedExpression(input);
    return 0;
}

void verifyBalancedExpression(std::string input)
{
    std::cout << "Expression to evaluate <" << input << ">\n";
    std::vector <char> openTerms;
    openTerms.push_back('(');
    openTerms.push_back('[');
    openTerms.push_back('{');

    std::vector <char> closeTerms;
    closeTerms.push_back(')');
    closeTerms.push_back(']');
    closeTerms.push_back('}');

    openCloseTermTuplesT myTuples[3];
    myTuples[0].openTerm  = '(';
    myTuples[0].closeTerm = ')';
    myTuples[1].openTerm  = '{';
    myTuples[1].closeTerm = '}';
    myTuples[2].openTerm  = '[';
    myTuples[2].closeTerm = ']';

    std::stack <char> expression;

    int strlen = input.size();
    //std::cout << "strlen: " << strlen << std::endl;
    for(int i = 0; i < strlen; i++)
    {
        if (std::find(openTerms.begin(), openTerms.end(), input[i])!= openTerms.end())
        {
            //std::cout << "This is an open term " << input[i] << std::endl;
            expression.push(input[i]);
        }
        else if (std::find(closeTerms.begin(), closeTerms.end(), input[i])!= closeTerms.end())
        {
            //std::cout << "This is a close term " << input[i] << std::endl;
            char previous_open_term = expression.top();
            //std::cout << "Previous open term was " << previous_open_term << std::endl;
            for(int j = 0; j < 3; j++)
            {
                if(previous_open_term == myTuples[j].openTerm)
                {
                    if(myTuples[j].closeTerm == input[i])
                    {
                        //std::cout << "It's a match" << std::endl;
                        expression.pop();
                        break;
                    }
                    else
                    {
                        std::cout << "This is not a balanced expression" << std::endl;
                        std::cout << "Mismatch at previous parantheses " << previous_open_term << std::endl;
                        std::cout << "Next paranthesis " << input[i] << std::endl;
                        return;
                    }
                }
                else
                    continue;
            }
        }
    }
    if(expression.empty())
        std::cout << "This is a balanced expression" << std::endl;
    else
        std::cout << "This is not a balanced expression" << std::endl;
}
