#include <bits/stdc++.h>

using namespace std;

int compare(const void *a, const void *b)
{
    if (*(int *)a > *(int *)b)
    {
        return 1;
    }
    else if (*(int *)a == *(int *)b)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

int ceil_log2(int num)
{
    int start = 1;
    // cout << num << endl;
    while (start < num)
    {
        start <<= 1;
    }
    // cout << start << endl;
    return start;
}

int floor_log2(int num)
{
    int start = 1;
    int prev = 1;
    // cout << num << endl;
    while (start <= num)
    {
        prev = start;
        start <<= 1;
    }
    // cout << start << endl;
    return prev;
}

int binSearch(int *L, int low, int high, int val)
{

    if (high <= low)
    {
        if (low < 0)
        {
            return -1;
        }
        if (L[low] == -1)
        {
            return low;
        }
        if (L[low] < val)
        {
            return low + 1;
        }
        else
        {
            return low;
        }
    }

    int mid1 = (low + high) / 2;
    int mid2 = (low + high) / 2;
    while (L[mid1] == -1 and mid1 >= low)
    {
        mid1--;
    }
    while (L[mid2] == -1 and mid2 <= high)
    {
        mid2++;
    }
    if (L[mid1] == -1 && L[mid2] == -1)
    {
        return -1;
    }

    if (mid1 < low && mid2 > high)
    {
        mid1 = (low + high) / 2;
        return low;
    }

    else if (mid1 >= low && mid2 > high)
    {
        if (L[mid1] == val)
        {
            return mid1;
        }
        else if (L[mid1] > val)
        {
            return binSearch(L, low, mid1 - 1, val);
        }
        else
        {
            return binSearch(L, mid1 + 1, high, val);
        }
    }

    else if (mid1 < low && mid2 <= high)
    {
        if (L[mid2] == val)
        {
            return mid2;
        }
        else if (L[mid2] < val)
        {
            return binSearch(L, mid2 + 1, high, val);
        }
        else
        {
            return binSearch(L, low, mid2 - 1, val);
        }
    }
    else
    {
        if (L[mid1] == val)
        {
            return mid1;
        }
        else if (L[mid2] == val)
        {
            return mid2;
        }
        else if (L[mid1] > val)
        {
            return binSearch(L, low, mid1 - 1, val);
        }
        else if (L[mid2] < val)
        {
            return binSearch(L, mid2 + 1, high, val);
        }
    }

    return -1;
}

void check_sorted(int *newL, int size)
{

    int c = 0;

    // for(int i=0;i<size;i++){
    //     cout << newL[i] << " ";
    // }
    // cout << endl;

    // cout << size << endl;

    for (int i = 1; i < size; i++)
    {
        if (newL[i] < newL[i - 1])
        {
            c++;
        }
        // cout << newL[i] << " ";
    }
    // cout << endl;

    cout << c << " Not Done" << endl;
}

// basically store 3 values => actual value, if element is present on the left, if element is present on the right. then add elements using bin search

// void rebalance(int* L, int size, int epsilon){
//     int *newL = (int *)malloc(sizeof(int)*size);
//     int curr = 0;
//     for(int i=0; i<(size/2); i++){
//         // cout << L[i] << " ";
//         if(L[i]==-1){
//             continue;
//         }
//         newL[curr++]=L[i];
//         for(int j=0; j<epsilon; j++){
//             newL[curr++] = -1;
//         }
//     }
//     for(int i=0;i<size;i++){
//         if(curr==i){
//             newL[curr++] = -1;
//         }
//         // cout << newL[i] << " ";
//         L[i]=newL[i];
//     }
//     // cout << endl;
//     free(newL);
// }

void rebalance(int *L, int size, int epsilon)
{
    int *newL = (int *)malloc(sizeof(int) * size);
    int curr = 0;
    for (int i = 0; i < (size / 2); i++)
    {
        // cout << L[i] << " ";
        if (L[i] == -1)
        {
            continue;
        }
        for (int j = 0; j < epsilon; j++)
        {
            newL[curr++] = -1;
        }
        newL[curr++] = L[i];
    }
    for (int i = 0; i < size; i++)
    {
        if (curr == i)
        {
            newL[curr++] = -1;
        }
        // cout << newL[i] << " ";
        L[i] = newL[i];
    }
    // cout << endl;
}

void normLibSort(int *L, int size, int epsilon)
{
    int tot = ceil_log2(size);
    int *newL = (int *)malloc(sizeof(int) * tot * (1 + epsilon));
    int curr_size = 1 + epsilon;

    for (int i = 0; i < tot * (1 + epsilon); i++)
    {
        newL[i] = -1;
    }

    // size = 2;

    // cout << size << endl;

    for (int i = 0; i < size; i++)
    {
        if (i == curr_size / (1 + epsilon))
        {
            curr_size *= 2;
            // if(size==524288){
            //     cout << curr_size << endl;
            // }
            rebalance(newL, curr_size, epsilon);
        }

        int curr = L[i];
        // cout << i << " ";
        int start = binSearch(newL, 0, curr_size - 1, curr);
        int j = start;
        if (j == -1)
        {
            // cout << i << " ";
            newL[i] = curr;
            continue;
        }
        // cout << start << " ";
        for (j; newL[j] != -1; j++)
        {
            // cout << curr << " ";
            if (curr < newL[j])
            {
                int temp = curr;
                curr = newL[j];
                newL[j] = temp;
            }
        }
        newL[j] = curr;
        // check_sorted(newL,curr_size);
    }
    // cout << endl;

    int curr = 0;
    // cout << "Here" << endl;
    for (int i = 0; i < size; i++)
    {
        // cout << newL[curr] << " ";

        if (newL[curr++] == -1)
        {
            i--;
            continue;
        }
        L[i] = newL[curr - 1];
    }
    // cout << endl;
    free(newL);
}

void insertSort(int *L, int size)
{

    for (int i = 0; i < size; i++)
    {
        int curr = L[i];
        int start = binSearch(L, 0, i - 1, curr);
        if (start == -1)
        {
            L[i] = curr;
            continue;
        }
        for (int j = start; j < i; j++)
        {
            if (curr < L[j])
            {
                int temp = curr;
                curr = L[j];
                L[j] = temp;
            }
        }
        L[i] = curr;
    }
    // check_sorted(newL,size);
}

void merge(int *L, int i, int j, int k)
{
    int currL = i;
    int currR = j + 1;

    int *newArr = (int *)malloc(sizeof(int) * (k - i + 1));

    for (int index = 0; index < (k - i + 1); index++)
    {
        if (currL > j)
        {
            newArr[index] = L[currR++];
        }
        else if (currR > k)
        {
            newArr[index] = L[currL++];
        }
        else
        {
            if (L[currL] > L[currR])
            {
                newArr[index] = L[currR++];
            }
            else
            {
                newArr[index] = L[currL++];
            }
        }
    }

    for (int index = 0; index < (k - i + 1); index++)
    {
        L[i + index] = newArr[index];
    }
    free(newArr);
}

void mergeSort(int *L, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(L, mid + 1, right);
        mergeSort(L, left, mid);
        merge(L, left, mid, right);
    }
}

// void libMerge(int* L, int size, int* sizes, int num){
//     int* newL = (int*)malloc(sizeof(int)*size);
//     // ll* merging = (ll*)malloc(sizeof(ll));
//     // merging->head = NULL;
//     int currs[num];
//     for(int i=0;i<num;i++){
//         currs[i] = sizes[i];
//     }

//     for(int i=0;i<size;i++){
//         int index = 0;
//         int curr = -1;
//         for(int j=0;j<num; j++){
//             if(currs[j] != sizes[j+1]){
//                 if(curr == -1){
//                     index = j;
//                     curr = L[currs[j]];
//                 }
//                 else if(L[currs[j]] < curr){
//                     curr = L[currs[j]];
//                     index = j;
//                 }
//             }
//         }
//         currs[index]++;
//         newL[i] = curr;
//     }

//     for(int i=0;i<size;i++){
//         L[i] = newL[i];
//     }
//     free(newL);
// }

// void preProcessingLibSort(int* L, int size, int epsilon){
//     int curr = size;
//     int i=0;
//     int num = 0;
//     while(curr>0){
//         num += curr & 1;
//         curr>>=1;
//     }

//     curr = size;
//     int sizes[num+1];
//     sizes[0]=0;
//     int curr_index = 1;
//     while(curr>0){
//         if(curr & 1){
//             sizes[curr_index] = sizes[curr_index-1] + (1<<i);
//             // cout << sizes[curr_index] << " " << sizes[curr_index-1] << " " << (1<<i) << endl;
//             curr_index++;
//             normLibSort(L+sizes[curr_index-2],sizes[curr_index-1] - sizes[curr_index-2],epsilon);
//         }
//         curr>>=1;
//         i++;
//     }

//     libMerge(L,size,sizes,num);

// }

typedef struct Node
{
    int size;
    int curr;
    struct Node *next;
    struct Node *prev;
} node;

typedef struct LL
{
    node *head;
    node *tail;
    int size;
} ll;

node *createNode(int prev, int i, ll *sizes)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->prev = sizes->tail;
    newNode->next = NULL;
    newNode->curr = prev;
    newNode->size = prev + (1 << i);
    // cout << newNode->curr << " " << newNode->size << endl;
    if (newNode->prev != NULL)
    {
        newNode->prev->next = newNode;
        sizes->tail = newNode;
    }
    else
    {
        sizes->head = newNode;
        sizes->tail = newNode;
    }

    return newNode;
}

void freeNode(node *myNode, ll *sizes)
{
    if (myNode->prev == NULL)
    {
        sizes->head = myNode->next;
    }
    else
    {
        myNode->prev->next = myNode->next;
    }
    if (myNode->next == NULL)
    {
        sizes->tail = myNode->prev;
    }
    else
    {
        myNode->next->prev = myNode->prev;
    }

    free(myNode);
}

void libMerge(int *L, int size, ll *sizes)
{
    int *newL = (int *)malloc(sizeof(int) * size);
    // ll* merging = (ll*)malloc(sizeof(ll));
    // merging->head = NULL;

    for (int i = 0; i < size; i++)
    {
        node *myNode = sizes->head;
        int curr = L[sizes->head->curr];
        node *currNode = sizes->head->next;
        while (currNode != NULL)
        {
            if (L[currNode->curr] < curr)
            {
                curr = L[currNode->curr];
                myNode = currNode;
            }
            currNode = currNode->next;
        }
        newL[i] = curr;
        myNode->curr++;
        if (myNode->curr == myNode->size)
        {
            freeNode(myNode, sizes);
        }
        if (sizes->head == NULL)
        {
            break;
        }
    }

    free(sizes);

    for (int i = 0; i < size; i++)
    {
        L[i] = newL[i];
    }
    free(newL);
}

void preProcessingLibSort(int *L, int size, int epsilon)
{
    int curr = size;
    int i = 0;
    int num = 0;
    while (curr > 0)
    {
        num += curr & 1;
        curr >>= 1;
    }

    // cout << num << endl;

    curr = size;
    // int sizes[num+1];
    int prev = 0;
    ll *sizes = (ll *)malloc(sizeof(ll));
    sizes->head = NULL;
    sizes->tail = sizes->head;
    sizes->size = num;
    // sizes[0]=0;
    int curr_index = 1;
    while (curr > 0)
    {
        if (curr & 1)
        {
            // sizes[curr_index] = sizes[curr_index-1] + (1<<i);
            createNode(prev, i, sizes);
            // cout << sizes[curr_index] << " " << sizes[curr_index-1] << " " << (1<<i) << endl;
            curr_index++;
            // cout << (1<<i) << endl;
            normLibSort(L + prev, (1 << i), epsilon);
            // cout << "Done" << endl;
            prev += (1 << i);
        }
        curr >>= 1;
        i++;
    }

    libMerge(L, size, sizes);
}

int main()
{
    int size = 100000;
    size = 8;
    // int epsilon = 100;

    // int L[size] = {6,4,2,1,7,3,8,5};
    // FILE *f = fopen("./positive_random.txt", "r");
    // string s = "";
    // char c = fgetc(f);
    // while (c != EOF)
    // {
    //     s+=c;
    //     c = fgetc(f);
    // }

    // istringstream iss(s);
    // string word;
    // size = 0;
    // while (iss >> word)
    // {
    //     // cout << word << endl;
    //     size++;
    // }
    // int *L= (int *)malloc(sizeof(int)*size);;
    // istringstream iss2(s);
    // int ind = 0;
    // while (iss2 >> word)
    // {
    //     // cout << word << endl;
    //     L[ind] = stoi(word);
    //     ind++;
    // }
    srand(time(0));

    for (int arraysize2 = 1000; arraysize2 <= 1000000; arraysize2 *= 10)
    {
        for (int i = 0; i < 4; i++)
        {
            int x = arraysize2 / 10;
            int arraysize = rand() % (arraysize2 - x) + x;
            // int arraysize = arraysize2;
            // int arraysize = 524288;
            // cout << endl << "Array Size = " << arraysize << endl;
            // cout << endl << "Epsilon " << epsilon << ":" << endl;
            double avgs[23] = {0};
            // int x = arraysize2 / 10;
            string sorts[23] = {"QSort ", "Insertion ", "Library Epsilon 1 ", "Library Epsilon 2 ", "Library Epsilon 3 ", "Library Epsilon 4 ", "Library Epsilon 5 ", "Library Epsilon 6 ", "Library Epsilon 7 ", "Library Epsilon 8 ", "Library Epsilon 9 ", "Library Epsilon 10 ", "Optimized Epsilon 1 ", "Optimized Epsilon 2 ", "Optimized Epsilon 3 ", "Optimized Epsilon 4 ", "Optimized Epsilon 5 ", "Optimized Epsilon 6 ", "Optimized Epsilon 7 ", "Optimized Epsilon 8 ", "Optimized Epsilon 9 ", "Optimized Epsilon 10 ", "Merge "};
            // string sorts[5] = {"QSort ", "Insertion ", "Library Epsilon 2 ","Optimized Epsilon 2 ", "Merge "};
            for (int iter = 0; iter < 10; iter++)
            {
                // cout << endl;
                // cout << endl << "Iteration " << iter+1 << ":" << endl;
                int *L = (int *)malloc(sizeof(int) * arraysize);
                int *Lglobal = (int *)malloc(sizeof(int) * arraysize);

                srand(time(0));

                for (int i = 0; i < arraysize; i++)
                {
                    L[i] = rand();
                    Lglobal[i] = L[i];
                }

                // sort(L, L + arraysize, [](int a, int b) { return a > b; });
                // sort(Lglobal, Lglobal + arraysize, [](int a, int b) { return a > b; });

                // sort(L, L + arraysize/2);
                // sort(Lglobal, Lglobal + arraysize/2);

                clock_t begin, end;

                begin = clock();
                qsort(L, arraysize, sizeof(int), compare);
                end = clock();

                check_sorted(L,size);
                avgs[0] += (double)(end - begin) / (10 * CLOCKS_PER_SEC);
                // cout << sorts[0] << arraysize << " " << (double)(end - begin) / CLOCKS_PER_SEC << endl;

                for (int i = 0; i < arraysize; i++)
                {
                    L[i] = Lglobal[i];
                }

                begin = clock();
                insertSort(L, arraysize);
                end = clock();

                check_sorted(L,size);
                avgs[1] += (double)(end - begin) / (10 * CLOCKS_PER_SEC);
                // cout << sorts[1] << arraysize << " " << (double)(end - begin) / CLOCKS_PER_SEC << endl;

                for (int epsilon = 1; epsilon <= 10; epsilon++)
                {
                    for (int i = 0; i < arraysize; i++)
                    {
                        L[i] = Lglobal[i];
                    }

                    begin = clock();
                    normLibSort(L, arraysize, epsilon);
                    end = clock();

                    check_sorted(L,size);
                    avgs[1 + epsilon] += (double)(end - begin) / (10 * CLOCKS_PER_SEC);
                    // avgs[2] += (double)(end - begin) / (1 * CLOCKS_PER_SEC);
                    // cout << sorts[1+epsilon] << arraysize << " " << (double)(end - begin) / CLOCKS_PER_SEC << endl;
                }

                for (int epsilon = 1; epsilon <= 10; epsilon++)
                {

                    for (int i = 0; i < arraysize; i++)
                    {
                        L[i] = Lglobal[i];
                    }

                    // cout << "Here" << endl;

                    begin = clock();
                    preProcessingLibSort(L, arraysize, epsilon);
                    end = clock();


                    // if(epsilon==2){
                    check_sorted(L,arraysize);
                    //     cout << "Optimised " << (double)(end - begin) / (10*CLOCKS_PER_SEC) << endl;
                    // }
                    avgs[11 + epsilon] += (double)(end - begin) / (10 * CLOCKS_PER_SEC);
                    // avgs[3] += (double)(end - begin) / (1 * CLOCKS_PER_SEC);
                    // cout << sorts[11+epsilon] << arraysize << " " << (double)(end - begin) / CLOCKS_PER_SEC << endl;
                }

                for (int i = 0; i < arraysize; i++)
                {
                    L[i] = Lglobal[i];
                }

                begin = clock();
                mergeSort(L, 0, arraysize - 1);
                end = clock();

                check_sorted(L,size);
                avgs[22] += (double)(end - begin) / (10 * CLOCKS_PER_SEC);
                // avgs[4] += (double)(end - begin) / (1 * CLOCKS_PER_SEC);
                // cout << sorts[22] << arraysize << " " << (double)(end - begin) / CLOCKS_PER_SEC << endl;

                // if (arraysize == 100000000)
                // {for(int i=0; i<arraysize; i++)
                // {
                //     cout << Lglobal[i] << endl;
                // }}

                free(L);
                free(Lglobal);
            }

            cout << endl;

            for (int i = 0; i < 23; i++)
            {
            //     // if(sorts[i]!="Insertion "){
                    cout << sorts[i] << arraysize << " " << avgs[i] << endl;
            //     // }
            }
        }
    }
    return 0;
}
