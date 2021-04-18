/** ****************************************************************************
 *
 * Fisier header pentru structurile necesare pentru pacienti.
 *
 ******************************************************************************/
#pragma once

#include <cstdint>
#include <string>

struct Patient {
    std::string firstName;
    std::string lastName;
    int age;
    char gender;
};
