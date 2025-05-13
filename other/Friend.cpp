#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
#define UID_START 100000
using namespace std;

class AbstractUser {
public:
    AbstractUser(string& name) : username(name){
        allUserCount++;
        allUser.push_back(*this);
        cout << "注册了一名新用户" << name << endl;
    }

    // 删除用户
    bool delUser() {
        if(!this->isDeleted || this->UID < allUserCount + UID_START) {
            this->isDeleted = true;
            return true;
        } else {
            cout << "错误的操作，你不能删除一个不存在或已被标记为删除的账户" << endl;
            return false;
        }
    }

    // 获取用户对象引用
    static AbstractUser& getUser(const int& userID) {
        if(userID >= allUserCount || allUser[userID].isDeleted){
            cout << "错误的操作，你不能获取一个不存在或已被标记为删除的账户" << endl;
            return INVALID_USER;
        } else {
            return allUser[userID];
        }
    }

    // 添加朋友
    bool addFriend(const int& friendUID) {
        AbstractUser& tempUser = getUser(friendUID);
        if(tempUser.username != INVALID_USER.username) {
            tempUser.friends.insert(this->UID);
            this->friends.insert(tempUser.UID);

            return true;
        } else {
            return false;
        }
    }

    // 朋友推荐
    void recommendFriend();

private:
    const string username;
    const int UID = UID_START + allUserCount;
    static vector<AbstractUser> allUser;
    static AbstractUser INVALID_USER;
    static int allUserCount;
    bool isDeleted = false;
    set<int> friends;
};

string INVALID_USER_NAME = "INVALID_USER";
int AbstractUser::allUserCount = 0;
AbstractUser AbstractUser::INVALID_USER(INVALID_USER_NAME);

void AbstractUser::recommendFriend() {
    if (this->isDeleted) {
        cout << "错误的操作，已删除用户无法获取好友推荐" << endl;
        return;
    }

    // 收集所有好友的好友
    set<int> candidates;
    for (int friendUID : this->friends) {
        AbstractUser& friendUser = AbstractUser::getUser(friendUID);
        if (!friendUser.isDeleted) {
            candidates.insert(friendUser.friends.begin(), friendUser.friends.end());
        }
    }

    // 过滤掉直接好友和自己
    candidates.erase(this->UID); // 移除自己
    for (int friendUID : this->friends) {
        candidates.erase(friendUID); // 移除直接好友
    }

    // 计算每个候选用户的 Jaccard
    map<int, double> recommendations;
    int uFriendCount = this->friends.size();

    for (int candidateUID : candidates) {
        AbstractUser& candidate = AbstractUser::getUser(candidateUID);
        if (candidate.isDeleted) {
            continue;
        }

        int cFriendCount = candidate.friends.size();

        // 计算共同好友数
        set<int> commonFriends;
        set_intersection(this->friends.begin(), this->friends.end(),
                         candidate.friends.begin(), candidate.friends.end(),
                         inserter(commonFriends, commonFriends.begin()));
        int commonCount = commonFriends.size();

        // 计算 Jaccard
        double jaccard = 0.0;
        if (uFriendCount + cFriendCount - commonCount > 0) {
            jaccard = (double)commonCount / (uFriendCount + cFriendCount - commonCount);
        }

        recommendations.insert({candidateUID, jaccard});
    }

    // 输出结果
    cout << "根据你的社交网络，你可能认识以下用户：" << endl;
    for (const auto& rec : recommendations) {
        AbstractUser& user = AbstractUser::getUser(rec.first);
        cout << "用户名: " << user.username << " (相似度: " << rec.second * 100 << "%)" << endl;
    }
}

