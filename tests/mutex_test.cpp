/* Copyright (c) 2022 Djones A. Boni - MIT License */

#include "librertos.h"

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

TEST_GROUP (Mutex)
{
    mutex_t mtx;

    void setup() { mutex_init(&mtx); }
    void teardown() {}
};

TEST(Mutex, Unlocked_Locks)
{
    LONGS_EQUAL(SUCCESS, mutex_lock(&mtx));
}

TEST(Mutex, Locked_CannotLock)
{
    mutex_lock(&mtx);
    LONGS_EQUAL(FAIL, mutex_lock(&mtx));
}

TEST(Mutex, Unlocked_CannotUnlock)
{
    LONGS_EQUAL(FAIL, mutex_unlock(&mtx));
}

TEST(Mutex, Locked_Unlocks)
{
    mutex_lock(&mtx);
    LONGS_EQUAL(SUCCESS, mutex_unlock(&mtx));
}

TEST(Mutex, IsLocked)
{
    LONGS_EQUAL(0, mutex_islocked(&mtx));

    mutex_lock(&mtx);
    LONGS_EQUAL(1, mutex_islocked(&mtx));
}
