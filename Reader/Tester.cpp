/**
 * \brief èrÛd≥o klasy testujπcej
 * \file Tester.cpp
 * \author Pawel Iwaneczko
 * \copyright Copyright 2017 HTeam. All rights reserved. 
 */
#include <cassert>
#include <iostream>
#define private public
#define protected public
#include "Logger.h"
#include "BinaryReader.h"
using namespace std;


#ifndef TESTER

#define USERNAME USER_NAME " " USER_SURNAME
void * TesterConstructor(uint8_t type, const char *filePath, bool binary)
{
    return type == 0 ? (void *)(new CLogger(filePath, binary)) : (void *)(new CBinaryReader(filePath));
}
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
size_t TesterDestructor(uint8_t type, void *ptr)
{
    if (type == 0)delete (CLogger *)ptr;
    else delete (CBinaryReader*)ptr;
    return stats.Count();
}

size_t TesterHelper(uint8_t type, uint8_t func, void *ptr, void *data, size_t *dlen)
{
    size_t res = ptr != nullptr ? 0 : 1;
    if (!res) {
        switch (type)
        {
        case 0: {
            CLogger &l = *(CLogger *)ptr;
            switch (func) {
            case 0:
                l.file.close();
                break;
            case 1:
                assert(data != nullptr);
                ((CLogger*)ptr)->file.open((const char *)data, l.binary ? ios::binary : 0);
                break;
            case 2:
                assert(data != nullptr && dlen != nullptr && *dlen > 0);
                {
                    vector<point_t> pv(*dlen / sizeof(point_t));
                    memcpy(&pv[0], data, *dlen);
                    res = l.Log(pv);
                }
                break;
            }}
            break;
        case 1: {
            CBinaryReader &r = *(CBinaryReader *)ptr;
            switch (func) {
            case 0:
                r.file.close();
                break;
            case 1:
                assert(data != nullptr);
                r.file.open((const char *)data, ios::binary);
                break;
            case 2:
                assert(data != nullptr && dlen != nullptr);
                {
                    vector<point_t> pv = { ((point_t *)data)[0] };
                    res = r.ReadFile(pv);
                    size_t bytes = pv.size() * sizeof(point_t);
                    if (bytes <= (*dlen)) {
                        memcpy_s(data, *dlen, pv.data(), bytes);
                    }
                    *dlen = bytes;
                }
                break;
            }}
            break;
        }
    }
    return res;
}
#endif /* !TESTER */
