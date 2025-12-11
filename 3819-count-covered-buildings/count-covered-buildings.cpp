class Solution {
public:
    int countCoveredBuildings(int nn, vector<vector<int>>& build) {
          int n = (int)build.size();           //compute n from build
        vector<pair<int,int>> vh(n);
        vector<pair<int,int>> vv(n);

        int i = 0;
        while (i < n)
        {
            int x = build[i][0];
            int y = build[i][1];

            vh[i] = make_pair(x, y);   // (x,y) for vertical searches (same x)
            vv[i] = make_pair(y, x);   // (y,x) for horizontal searches (same y)

            i = i + 1;
        }

        sort(vh.begin(), vh.end());   // sorted by x then y
        sort(vv.begin(), vv.end());   // sorted by y then x

        int count = 0;
        i = 0;

        while (i < n)
        {
            int x = build[i][0];
            int y = build[i][1];

            bool hasVertical = false;
            bool hasHorizontal = false;

            // VERTICAL CHECK: existence of same-x with y' > y and y' < y
            auto itUp = upper_bound(vh.begin(), vh.end(), make_pair(x, y));
            auto itDown = lower_bound(vh.begin(), vh.end(), make_pair(x, INT_MIN));
            if (itUp != vh.end() && itDown != vh.end())
            {
                if (itUp->first == x && itUp->second > y)
                {
                    if (itDown->first == x && itDown->second < y)
                    {
                        hasVertical = true;
                    }
                }
            }

            // HORIZONTAL CHECK: existence of same-y with x' > x and x' < x
            auto itRight = upper_bound(vv.begin(), vv.end(), make_pair(y, x));
            auto itLeft = lower_bound(vv.begin(), vv.end(), make_pair(y, INT_MIN));
            if (itRight != vv.end() && itLeft != vv.end())
            {
                if (itRight->first == y && itRight->second > x)
                {
                    if (itLeft->first == y && itLeft->second < x)
                    {
                        hasHorizontal = true;
                    }
                }
            }

            if (hasVertical && hasHorizontal)
            {
                count = count + 1;
            }

            i = i + 1;
        }

        return count;
    }
};