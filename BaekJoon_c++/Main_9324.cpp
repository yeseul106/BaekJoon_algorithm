
#include <iostream>

#include <string>

using namespace std;



int main(void)

{

    ios_base::sync_with_stdio(0);

    cin.tie(0);


    int test_case;

    cin >> test_case;


    for (int t = 0; t < test_case; t++)

    {

        bool real = true;

        string s;

        cin >> s;



        int alphabet[26] = { 0 };

        for (int i = 0; i < s.length(); i++)

        {

            alphabet[s[i] - 'A']++;

            if (alphabet[s[i] - 'A'] == 3)

            {

                //���ڿ��� ��

                if (i == s.length() - 1)

                {

                    real = false;

                    break;

                }

                //���� �ε����� �ٸ� ����

                else if (s[i + 1] != s[i])

                {

                    real = false;

                    break;

                }

                i++;

                alphabet[s[i] - 'A'] = 0; // �ٽ� ��

            }

        }

        if (real)

            cout << "OK" << endl;

        else

            cout << "FAKE" << endl;

    }

    return 0;

}
