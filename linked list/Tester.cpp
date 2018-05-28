/**
 * \brief ród³o klasy testuj¹cej
 * \file Tester.cpp
 * \author Pawel Iwaneczko
 * \copyright Copyright 2017 HTeam. All rights reserved. 
 */
#include "CList.h"
using namespace std;


#ifndef TESTER
typedef CList TesterClass;
Tester *TesterConstructor() {
    return new TesterClass();
}

#define USERNAME USER_NAME " " USER_SURNAME
size_t TesterUserName(char *username, size_t usernameSize, uint8_t *group)
{
    size_t length = sizeof(USERNAME);
    memcpy_s(username, usernameSize, USERNAME, length);
    *group = USER_GROUP;
    return length;
}

namespace statistics {
    Stats::Stats() : initialized(), id(this_thread::get_id()), stats() {
        id = thread::id();
        initialized = true;
    }
    Stats::~Stats() {
        id = this_thread::get_id();
    }
    size_t Stats::Count() const {
        size_t count = 0;
        for (auto &s : stats) count += s.second;
        return count;
    }
    void Stats::AddPtr(void* ptr, size_t count)
    {
        if (initialized) {
            thread::id id = this_thread::get_id();
            if ((this->id == thread::id() || this->id != id) && locker.try_lock()) {
                this->id = id;
                stats.insert(make_pair(ptr, count));
                this->id = thread::id();
                locker.unlock();
            }
        }
    }
    void Stats::RemovePtr(void* ptr)
    {
        if (initialized) {
            thread::id id = this_thread::get_id();
            if ((this->id == thread::id() || this->id != id) && locker.try_lock()) {
                auto it = stats.find(ptr);
                if (it != stats.end()) {
                    this->id = id;
                    stats.erase(it);
                    this->id = thread::id();
                }
                locker.unlock();
            }
        }
    }
};

static statistics::Stats stats;
void* operator new (size_t count) {
    void* ptr = malloc(count);
    stats.AddPtr(ptr, count);
    return ptr;
}
void operator delete (void* ptr) {
    stats.RemovePtr(ptr);
    free(ptr);
}
void operator delete[](void* ptr) {
    stats.RemovePtr(ptr);
    free(ptr);
}
size_t TesterDestructor(void *ptr) {
    delete (TesterClass*)ptr;
    return stats.Count();
}
#endif /* !TESTER */
