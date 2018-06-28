https://www.geeksforgeeks.org/find-missing-number-arithmetic-progression/

https://drive.google.com/open?id=1DmJoio_2EtOLtYrjd3fKnoWr6XkmGynH (IMP) (DIFF)
https://drive.google.com/open?id=1GrKY7KCmQ0mNUnWx-IMf76AqFyBJaLEr (BRUTE FORCE)
(DRY RUN)
https://drive.google.com/open?id=10K1wCKGFdJeK84JslZl7dwNENCln_jtA
https://drive.google.com/open?id=1MfRM5kgzXO1MXpU9Oxf4m_7b0_kKj05N
https://drive.google.com/open?id=1hzudUNYWsgYBsQpr_3ofhu_OUQL_OWzw

(Algo)
https://drive.google.com/open?id=15q9pXpQJVZVABvG9R3CuKaO926fAGzPe


int missingNumber(vector<int> &nums){

    int n=nums.size();

    /// 1 or 2 elements are always correct
    if(n<3){

        return -1;

    }

    int a=nums[0];
    /// Assuming diff is integer
    /// And one of the term is missing(Won't work if no term missing)
    /// It will calculate wrong difference in that case
    int diff=(nums[n-1]-nums[0])/n;

    int start=0,mid,end=n-1;

    while(start<=end){

        mid=(start+end)/2;

        if(nums[mid]==((mid*diff)+a)){

            /// It means mid at it's right position
            /// So there can't be any missing number on left side
            start=mid+1;
        }

        else{

            /// 2 cases either mid at position of missing no or missing no further on left
            if(nums[mid]-nums[mid-1]==diff){

                /// It means mid at correct position
                /// Move left
                end=mid-1;

            }
            else{

                /// Mid at position of missing no
                return ((mid*diff)+a);

            }
        }
    }
    return -1;  /// No missing num found(Doesn't work returns a random no instead)
}

