#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

char* gapcDebugMenuEntryNames[] = {
    "Play Sound",
    "Test Entry 2",
    "Test Entry 3",
    "Test Entry 4",
    "Test Entry 5",
    "Test Entry 6 (no options)",
    "Test Entry 7 (no options)"
};

CB4DebugVSelectEntry gaDebugMenuEntries[sizeof(gapcDebugMenuEntryNames) / sizeof(gapcDebugMenuEntryNames[0])];

char *gapcDebugMenuNoOptions[] = {
    " "
};

char* gapcDebugMenuEntry1Options[] = {
    "Entry 1 Test Option 1",
    "Entry 1 Test Option 2",
    "Entry 1 Test Option 3",
    "Entry 1 Test Option 4",
    "Entry 1 Test Option 5"
};

char* gapcDebugMenuEntry2Options[] = {
    "Entry 2 Test Option 1",
    "Entry 2 Test Option 2",
    "Entry 2 Test Option 3",
    "Entry 2 Test Option 4",
    "Entry 2 Test Option 5"
};

char* gapcDebugMenuEntry3Options[] = {
    "Entry 3 Test Option 1",
    "Entry 3 Test Option 2",
    "Entry 3 Test Option 3",
    "Entry 3 Test Option 4",
    "Entry 3 Test Option 5"
};

char* gapcDebugMenuEntry4Options[] = {
    "Entry 4 Test Option 1",
    "Entry 4 Test Option 2",
    "Entry 4 Test Option 3",
    "Entry 4 Test Option 4",
    "Entry 4 Test Option 5"
};

char* gapcDebugMenuEntry5Options[] = {
    "Entry 5 Test Option 1",
    "Entry 5 Test Option 2",
    "Entry 5 Test Option 3",
    "Entry 5 Test Option 4",
    "Entry 5 Test Option 5"
};

#endif
