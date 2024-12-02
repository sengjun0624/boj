#include <string>
#include <vector>
#include <map>
#include <queue>
#include<algorithm>
#include<iostream> 

using namespace std;
map<string, int>best_genres;
map<string, priority_queue<pair<int,int>>>best_two;
vector<int> solution(vector<string> genres, vector<int> plays) {
    for(int i=0;i<genres.size();i++){
        // 일단 그 장르 데이터가 있는지 확인하고 , 데이터의 pq를 업데이트 해야하는경우에만 best_genres값을 바꿔야함.
        string cur = genres[i];
        //장르가 없는지 체크
        if(best_genres.find(cur) != best_genres.end()){
            //베스트 투를 선정하기위해 pq불러옴.
            //first= 장르, second= pq<int,int> 
            auto &pq = best_two[cur];
            //pq.first= 재생수 , pq.second=인덱스
            if(pq.size() >= 2){
                //장르에 빼야할 값빼줌
                    //새로 들어온 값 추가
                    best_genres[cur] += plays[i];
                    pq.push({-plays[i],i});
                    pq.pop(); 
            }else{
                pq.push({-plays[i],i});
                best_genres[cur]+=plays[i];
            }
        }else{
            best_genres[cur] = plays[i];
            best_two[cur];
            //재생수와 인덱스를 저장.
            best_two[cur].push({-plays[i],i});
        }
        
    }
    vector<pair<int,string>>v;
    
    for(auto pair : best_genres){
          v.push_back({pair.second,pair.first});
    }
    sort(v.begin(),v.end(),greater<>());
    // --- 여기까지 이제 장르별 두곡 뽑았고
    // for(auto pair : v)cout<<pair.first<<" "<<pair.second<<"\n";
    vector<int> answer;
    
    for(int i=0;i<v.size();i++){
        //큰 값의 장르명
        string key= v[i].second;
        auto& pq = best_two[key];
        vector<int>temp;
        while(!pq.empty()){
            temp.emplace_back(best_two[key].top().second);
            pq.pop();
        }
        for(int j=temp.size()-1 ;j>=0;j--){
            answer.emplace_back(temp[j]);
        }
    }
    return answer;
    
}