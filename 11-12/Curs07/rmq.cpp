#include <fstream>

using namespace std;

ifstream in ("rmq.in");
ofstream out ("rmq.out");

const int max_size = 1e5 + 1, rmax = 19;

int rmq[rmax][max_size], lg[max_size];

int main ()
{
    int n, q;
    in >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        in >> rmq[0][i];
    }
    for (int e = 1; (1 << e) <= n; e++)
    {
        for (int i = 1; i + (1 << e) - 1 <= n; i++)
        {
            rmq[e][i] = min(rmq[e - 1][i], rmq[e - 1][i + (1 << (e - 1))]);
        }
    }
    for (int i = 2; i <= n; i++)
    {
        lg[i] = lg[i / 2] + 1;
    }
    while (q--)
    {
        int x, y;
        in >> x >> y;
        int e = lg[y - x + 1];
        out << min(rmq[e][x], rmq[e][y - (1 << e) + 1]) << '\n';
    }
    in.close();
    out.close();
    return 0;
}