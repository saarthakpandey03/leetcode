class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());

        int n = people.size();
        int i = 0;
        int j =n-1;
        int boats = 0;
        while(i<=j){
            if(people[i] + people[j] <= limit){
                //do bande ek boat me ja rhe h 1 count hoga
                i++;
            }
    //dono nhi gye to j piche le aaya heavy vala nikl gya akela or 1 boat bhej diya
            j--;
            boats++;
        }
        return boats;
    }
};