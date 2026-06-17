#include <string>
#include <vector>
#include <iostream> 
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int idx = 0;
    int current_weight = 0;
    
    queue<int> bridge;
    for(int i = 0; i < bridge_length; ++i){
        bridge.push(0);
    }
    
    while(!bridge.empty()){
        answer++;
        current_weight -= bridge.front();
        bridge.pop();
        
        // 대기중인 트럭이 있는지 확인.
        // 원소의 사이즈가 트럭의 대수. 
        if (idx < truck_weights.size()) {
            
            // 현재 무게 + 올라갈 트럭의 무게보다 weight가 높아야 한다.
            if (current_weight + truck_weights[idx] <= weight) {
                // 트럭을 큐에 푸쉬를 하고, 
                bridge.push(truck_weights[idx]);
                // 현재 무게에 트럭 무게을 더함.
                current_weight += truck_weights[idx];
                idx++; 
            } else {
                // 없으면 공갈값
                bridge.push(0);
            }
        }
    }
    return answer;
}