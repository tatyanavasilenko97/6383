template <class T>
bool addFirstElement(treap<T>*& treapEl,QString firstWindow,QString secondWindow){
    int i = 0;
    int flagOne = 0,flagTwo = 0;
    int sch = 1;
    bool isCorrect = false;
    if (firstWindow[i]=='-'){
        sch =-1;
        ++i;
    }
    while (firstWindow[i].toLatin1()<=57&&firstWindow[i].toLatin1()>=48){
        flagOne+=firstWindow[i].toLatin1() - 48;
        flagOne*=10;
        isCorrect = true;
        ++i;
    }
    if(!isCorrect||i!=firstWindow.length()) return false;
    flagOne/=sch*10;

    i=0;
    sch = 1;
    isCorrect = false;
    if (secondWindow[i]=='-'){
        sch =-1;
        ++i;
    }
    while (secondWindow[i].toLatin1()<=57&&secondWindow[i].toLatin1()>=48){
        flagTwo+=secondWindow[i].toLatin1() - 48;
        flagTwo*=10;
        isCorrect = true;
        ++i;
    }
    if(!isCorrect||i!=secondWindow.length()) return false;
    flagTwo/=sch*10;
    treapEl->key = flagOne;
    treapEl->priority = flagTwo;
    return true;
}



template <class T>
QString addOrDelIntTreapElLine(treap<T>*& treapEl,QString sourceString,bool isAdd){
    int i = 0;
    int k = 0;
    QString result ="";
    QVector<int> newString(1);
    QVector< QVector<int> >addTreapEl;
    while (i<sourceString.length()){

        if (sourceString[i]!='('){
            return "Incorrect input data";
        } else{
            ++i;
            int sch = 1;
            int flag = 0;
            bool isCorrect = false;
            if (sourceString[i]=='-'){
                sch =-1;
                ++i;
            }
            while (sourceString[i].toLatin1()<=57&&sourceString[i].toLatin1()>=48){
                flag+=sourceString[i].toLatin1() - 48;
                flag*=10;
                isCorrect = true;
                ++i;
            }
            if(!isCorrect) return "Incorrect input data";
            newString[0] = sch*flag/10;
            addTreapEl.push_back(newString);

            if (sourceString[i]!=','){
                return "Incorrect input data";
            } else{
                ++i;
                int sch = 1;
                int flag = 0;
                bool isCorrect = false;
                if (sourceString[i]=='-'){
                    sch =-1;
                    ++i;
                }
                while (sourceString[i].toLatin1()<=57&&sourceString[i].toLatin1()>=48){
                    flag+=sourceString[i].toLatin1() - 48;
                    flag*=10;
                    isCorrect = true;
                    ++i;
                }
                if(!isCorrect) return "Incorrect input data";
                addTreapEl[k].push_back(sch*flag/10);
                ++k;
                ++i;
            }
        }
    }

    if (isAdd){
        treap<T>* newTreapEl = new treap<T>[addTreapEl.size()];
        for (int k = 0;k<addTreapEl.size();++k){
            bool res = false;
            newTreapEl[k].key  = addTreapEl[k][0];
            newTreapEl[k].priority = addTreapEl[k][1];
            isExistInTreapXorY(treapEl,newTreapEl+k,res);

            result+="Element ";
            result+="(" + QString::number(newTreapEl[k].key) + "," + QString::number(newTreapEl[k].priority)+")";
            if (isExistInTreap(treapEl,newTreapEl+k)){
                result+=" exist/";
            } else{
                if (res){
                    result += " uncorrect/x or y eq/";
                    delete (newTreapEl+k);
                } else{
                    result+=" not exists/ add /";
                    insertElInTreap(treapEl,newTreapEl+k);}}
            result += "\n";
        }
        return result;
    } else {
        treap<T>* newTreapEl = new treap<T>[addTreapEl.size()];
        for (int k = 0;k<addTreapEl.size();++k){
            if ((treapEl->left==NULL)&&(treapEl->right==NULL)){
                result+=("it last element/ if u del el u del tree / \n");
            }  else{
                newTreapEl[k].key  = addTreapEl[k][0];
                newTreapEl[k].priority = addTreapEl[k][1];
                result+="Element ";
                result+="(" + QString::number(newTreapEl[k].key) + "," + QString::number(newTreapEl[k].priority)+")";
                if (isExistInTreap(treapEl,newTreapEl+k)){
                    result+=" exist/ delete/";
                    deleteTreapEl(treapEl,(newTreapEl+k)->key);
                } else{
                    result+=" not exists/";}
                result += "\n";
            }}
        delete [] newTreapEl;
        return result;

    }
}

//template <class T>
int HeigthOfTree(const treap<int> &p){
    //struct treap<T>*& temp =p;
    int h1=0,h2=0;
    if(&p==NULL)return(0);
    if(p.left != nullptr){h1=HeigthOfTree(*p.left);}
    if(p.right!= nullptr){h2=HeigthOfTree(*p.right);}
    return(std::max(h1,h2)+1);
}

QString DelRandEl(treap<int> *p, int & level){
    srand(time(NULL));QString sourceString, ls;
    int rand_hei = rand() % 10;//HeigthOfTree(*p);
    treap<int> *& elem=p;int y;
    for (y = 0; y < rand_hei; y++) { //спускаемся от корня случайным образом
        if (elem->left != nullptr && elem->right != nullptr) //проверяем на наличие детей
            if (rand() % 2) elem = elem->left; else elem = elem->right;

        else if (elem->left != nullptr) elem = elem->left;
        else if (elem->right != nullptr) elem = elem->right;
        else break;

    }
    //if (elem->left == nullptr || elem->right == nullptr) continue;//если дочерних нет
    ls = "(" + QString::number(elem->key) + "," + QString::number(elem->priority) + ")" ;
    level = y;
    /*auto begin = std::chrono::steady_clock::now();//время 1 от нача программы
    sourceString = "(" + QString::number(elem->key) + "," + QString::number(elem->priority) + ")";
    ls += addOrDelIntTreapElLine(p,sourceString,false);

    auto end = std::chrono::steady_clock::now();//время 2 от нача программы
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);//время выполнения алгоритма удаления в НС
    ls += " The time: " + QString::number(elapsed_ms.count()) + " ns\n";
*/
    return ls;
}
