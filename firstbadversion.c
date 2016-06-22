
/* Important: Remember this  Computers in O(logn)
* Once a bad version no is detected, everything after that is a bad version.
*/
public int firstBadVersion(int n) {
    int left = 1;
    int right = n;
    while (left < right) {
        int mid = left + (right - left) / 2; // This is done so, overlap can be avoided.
        if (isBadVersion(mid)) {  // This  actually detects bad version of its
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

bool isBadVersion(int n){
//Customer implements this,
    return TRUE; or return FALSE;
}

int main(int argc, char *argv[]){

//Finds in O(logn) first bad version
firstBadVersion(1000);
//Other approach is O(n) where, it walks till 1000 linearly.

}