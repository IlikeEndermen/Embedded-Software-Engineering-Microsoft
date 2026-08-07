#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include<algorithm>
class UserProfile {
private:
    std::string username;
    std::string email;
    std::string passwordHash;
    std::string fullName;
    int age;
    std::vector<std::string> friends;
    bool isPrivateProfile;
    bool isVerified;
    std::string phoneNumber;
    // Private validation helpers
    bool isValidEmail(const std::string& email) const {
        std::regex emailPattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
        return std::regex_match(email, emailPattern);
    }    
    bool isValidUsername(const std::string& username) const {
        return username.length() >= 3 && username.length() <= 20;
    }
public:
    // Constructor with comprehensive validation
    UserProfile(const std::string& user, const std::string& mail, const std::string& name)
        : isPrivateProfile(true), isVerified(false), age(0) {        
        if (!setUsername(user)) {
            throw std::invalid_argument("Invalid username");
        }
        if (!setEmail(mail)) {
            throw std::invalid_argument("Invalid email address");
        }
        if (!setFullName(name)) {
            throw std::invalid_argument("Invalid full name");
        }
    }    
    // Getters for public information
    std::string getUsername() const { return username; }
    std::string getEmail() const { return email; }
    std::string getDisplayName() const {
        return isPrivateProfile ? username : fullName;
    }
    bool isProfilePrivate() const { return isPrivateProfile; }
    bool isUserVerified() const { return isVerified; }
    int getFriendCount() const { return friends.size(); }    
    // Secured setters with validation
    bool setUsername(const std::string& newUsername) {
        if (isValidUsername(newUsername)) {
            username = newUsername;
            return true;
        }
        std::cout << "Error: Username must be 3-20 characters long" << std::endl;
        return false;
    }    
    bool setEmail(const std::string& newEmail) {
        if (isValidEmail(newEmail)) {
            email = newEmail;
            return true;
        }
        std::cout << "Error: Invalid email format" << std::endl;
        return false;
    }    
    bool setFullName(const std::string& name) {
        if (!name.empty() && name.length() <= 100) {
            fullName = name;
            return true;
        }
        std::cout << "Error: Full name cannot be empty or exceed 100 characters" << std::endl;
        return false;
    }    
    bool setAge(int newAge) {
        if (newAge >= 13 && newAge <= 120) {
            age = newAge;
            return true;
        }
        std::cout << "Error: Age must be between 13 and 120" << std::endl;
        return false;
    }
    bool setPrivacyStatus(bool status){
        if (status == true){
            std::cout << "Error: Profile is already " << (status ? "private" : "public") << std::endl;    
        }
        isPrivateProfile = status;
        std::cout << "Profile has been set to " << (status ? "private" : "public") << std::endl;
        return false;
    }
    void togglePrivacy(){
        isPrivateProfile = !isPrivateProfile;
    }
    bool addFriend(UserProfile& friendUser){
        if(!isVerified){
            std::cout << "Error: Your account is not verified, you are unable to add/remove friends yet" << std::endl;
            return false;
        }
        if(!friendUser.isVerified){
            std::cout << "Error: Can't send a friend request to an unverified account" << std::endl;
            return false;
        }
        if(friendUser.isPrivateProfile){
            std::cout << "Error: Can't send a friend request to a private profile" << std::endl;
            return false;
        }
        friends.push_back(friendUser.username);
        std::cout << "You have added " << friendUser.username << " as a friend!" << '\n';
        std::cout << "You currently have " << friends.size() << " friends" << '\n';
        return true;
    }
    bool removeFriend(UserProfile& friendUser) {
    if (!isVerified) {
        std::cout << "Error: Your account is not verified, you are unable to add/remove friends yet" << std::endl;
        return false;
    }
    auto it = std::find(friends.begin(), friends.end(), friendUser.username);
    if (it == friends.end()) {
        std::cout << "Error: " << friendUser.username << " is not in your friends list" << std::endl;
        return false;
    }
    friends.erase(it);
    std::cout << "You have removed " << friendUser.username << " as a friend! Hope it wasn't personal..." << '\n';
    std::cout << "You currently have " << friends.size() << " friends" << '\n';
    return true;
    }

    // Your implementation here: Add methods for privacy settings, friend management, etc.    
    // Friend declarations for platform administration
    friend class PlatformModerator;
    friend void technicalSupport(UserProfile& user, const std::string& issue);
};


void technicalSupport(UserProfile& user, const std::string& issue){
        std::cout << "User " << user.username << " sent a ticket to the IT department with the following issue: " << issue << '\n';
        std::cout << "Beginning investigation..." << '\n';
}


class PlatformModerator{
public:

void accessUserInformation(UserProfile& user){
    std::cout << "\n=== USER PROFILE ===" << std::endl;
    std::cout << "Username: " << user.username << std::endl;
    std::cout << "Email: " << user.email << std::endl;
    std::cout << "Password Hash: " << user.passwordHash << std::endl;
    std::cout << "Legal Name: " << user.fullName << std::endl;
    std::cout << "Age: " << user.age << std::endl;
    std::cout << "Private?: " << user.isPrivateProfile << std::endl;
    std::cout << "Verified?: " << user.isVerified << std::endl;
    std::cout << "Phone Number: " << user.phoneNumber << std::endl;
    std::cout << "Number of friends: " << user.friends.size() << std::endl;
    for (int i = 0; i < user.friends.size(); i++){
        std::cout << "  - " << user.friends[i] << std::endl;
    }
    std::cout << "\n=== END OF PROFILE ===" << std::endl;
}

};


// Complete this implementation
int main() {
    // Your code here: Create UserProfile objects and demonstrate encapsulation    
    return 0;
}