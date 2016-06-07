#include"Tree.cpp"
Tree tree;
void InitData(bool is_t)
{
    vector <string> remain_attribute;
    vector <vector <string> > remain_state;
    for(int i = 1;i<5;i++){
        remain_attribute.push_back(state[0][i]);
    }
    for(unsigned int i = 0; i < state.size(); i++){
        remain_state.push_back(state[i]);
    }
    if(!is_t)
        tree.ComputeMapFrom2DVector();
    else{
        tree.FreeTree(tree.root);
        tree.root = NULL;
    }
    tree.root = tree.BulidDecisionTreeDFS(tree.root,remain_state,remain_attribute);
}
void Menu(){
    int act;
    bool loop = true;
    string filename;
    string str;
    string dec;
    while(loop){
        cout<<"======================Welcome to Decision_Tree system==========================="<<endl;
        cout<<"1、输入数据构建决策树"<<endl;
        cout<<"2、训练决策树"<<endl;
        cout<<"3、输出决策树"<<endl;
        cout<<"4、输入数据作出决策"<<endl;
        cout<<"5、退出系统"<<endl;
        cout<<"输入操作序号:";
        cin>>act;
        //system("cls");
        switch(act){
        case 1:
            cout<<"1、输入数据构建决策树"<<endl;
            cout<<"2、读入文件构建决策树"<<endl;
            cout<<"3、退出"<<endl;
            cout<<"输入操作序号:";
            cin>>act;
            switch(act){
            case 1:
                system("cls");
                tree.Input();
                break;
            case 2:
                tree.InputByFile();
                break;
            default:
                break;
            }
            InitData(false);
            break;
        case 2:
            {
                vector<string> data;
                cout<<"请输入数据训练决策树(输入end结束)："<<endl;
                string num = state[state.size()-1][0];
                char n[2];
                itoa(atoi(num.c_str()),n,10);
                string next(n);
                data.push_back(next);
                while(cin>>str&&str.compare("end")!=0){
                    data.push_back(str);
                }
                state.push_back(data);
                InitData(true);
                cout<<endl<<"决策树训练成功..."<<endl;
            }

            //16 Sunny Hot High Weak yes
            break;
        case 3:
            cout<<"the decision tree is :"<<endl;
            tree.PrintTree(tree.root,0);
            break;
        case 4:
            dec = tree.Make_Decision();
            cout<<"做出决策的结果为："<<dec<<endl;
            break;
        case 5:
            tree.FreeTree();
            loop = false;
            break;
        default:
            cout<<"please input the right num!"<<endl;
            if(cin.fail()){
                cin.clear();
                cin.sync();
            }
            break;
        }
        system("pause");
        system("cls");
    }
}
int main(){
    Menu();
	return 0;
}
