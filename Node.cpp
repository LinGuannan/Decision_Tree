#include<iostream>
#include<vector>
using namespace std;
class Node{//决策树节点
private:
	string value;//属性值
	string to_value;//到达的属性值
public:
	vector<Node *> childs;//所有的孩子
	Node(){
		value = "";
		to_value = "";
	}
	void setChild(Node *child){
	    childs.push_back(child);
	}
	vector<Node*> getChild(){
	    return childs;
	}
	void setValue(string v){
	    value = v;
	}
	void setTo_Value(string to){
	    to_value =to;
	}
	string getValue(){
	    return value;
	}
	string getTo_value(){
	    return to_value;
	}
};
