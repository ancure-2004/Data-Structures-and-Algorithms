){
            if(s1[i - 1] == s2[j - 1]){
                prev[j] = prev[j - 1] + prev[j];
            }
            else
                prev[j] = prev[j];
        }
    }

    cout << prev[m];