#include<map>
#include<string>
#include<vector>
#include<iostream>
#include<memory>
using namespace std;


struct HRML {
    string name;
    map<string, string> attrs; 
    vector< unique_ptr<HRML> > child;
    HRML * parent; 
    
    HRML():parent(nullptr){};
};

string hrml_query(HRML & root, string & query) {
    size_t start_pos = 0;
    size_t pos = 0;
    HRML * node = & root;
    HRML * child;

    while((pos = query.find(".", start_pos)) != string::npos){
        string tag_name = query.substr(start_pos, pos-start_pos);
        for(size_t n=0; n < node -> child.size(); ++n){
            child = node -> child[n].get();
            if(child -> name == tag_name){
                node = child;
                break;
            }
        }
        start_pos = pos;
    }

    pos=query.find("~", start_pos);
    string tag_name = query.substr(start_pos, pos - start_pos);
    string tag_attr = query.substr(pos, query.length() - pos);
    
    for(size_t n=0; n < node -> child.size(); ++n){
        child = node -> child[n].get();
        if(child -> name == tag_name){
            node = child;
            break;
        }
    }

    string attr_value = node -> attrs[tag_attr];

    return attr_value;
}


unique_ptr<HRML> input_line_parser(string & str) {
    size_t start_pos = 0;
    size_t pos = 0;
    vector<string> ele; 

    while((pos = str.find(' ', start_pos)) != string::npos){
       ele.push_back(str.substr(start_pos, pos - start_pos));
       start_pos = pos + 1;
    }
    ele.push_back(str.substr(start_pos, str.length()-1 - start_pos));

    if(ele[0].substr(0, 2) == "</"){
        //end of a node
        return nullptr;
    }else{
        //new node
        unique_ptr<HRML> node = make_unique<HRML>();
        node -> name = ele[0].substr(1, ele[0].length() - 1);
        for(size_t n = 0; n < (ele.size() - 1)/3; ++n ){
            string attr_name = ele[1+3*n];
            string attr_value = ele[1+3*n+2];
            node -> attrs [attr_name] = attr_value; 
        }
        return node;
    }

}


unique_ptr<HRML> hrml_input( size_t line_num ) {
    unique_ptr<HRML> root = make_unique<HRML>();
    root -> parent = nullptr;
    HRML * parent = root.get();

    size_t n;   
    string input_line;
    unique_ptr<HRML> node;

    n=0;
    while(n < line_num){
       getline(cin, input_line);
      // cin >> input_line;
       node = input_line_parser(input_line);
       if(nullptr == node){
           if(parent -> parent == nullptr){
                break;
           }else{
                parent = (parent -> parent).get();
           }
        }else{
           node -> parent = parent;
           (parent -> child).push_back( move(node) );
            parent = (parent -> child).back().get();
        }
		++n;
    }
    
    return root;
}

int main() {
    int N, Q; 
    string query;

    cin >> N >> Q; 
    cin.ignore();

    unique_ptr<HRML> root = hrml_input(N);

    for(size_t n=0; n< Q; ++n){
        cin >> query; 
        string result = hrml_query(*root, query);
        cout << result; 
    }

    return 0; 
}
