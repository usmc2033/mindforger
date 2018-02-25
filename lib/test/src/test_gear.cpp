/*
 test_gear.cpp     MindForger test utils and gears

 Copyright (C) 2016-2018 Martin Dvorak <martin.dvorak@mindforger.com>

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "test_gear.h"

namespace m8r {

using namespace std;

void printOutlineNotes(Outline* o)
{
    if(o) {
        cout << "Outline: " << o->getName() << endl;
        for(unsigned int i=0; i<o->getNotes().size(); i++) {
            cout << "  " << o->getNotes()[i]->getName() << endl;
        }
    } else {
        cout << "Outline is NULL" << endl;
    }
}

void createEmptyRepository(string& repositoryDir, map<string,string>& pathToContent)
{
    // clean
    removeDirectoryRecursively(repositoryDir.c_str());
    // create empty repo
    Installer installer{};
    installer.createEmptyMindForgerRepository(repositoryDir);
    // create content (path is expected to be absolute)
    if(pathToContent.size()) {
        for(auto& i:pathToContent) {
            stringToFile(i.first, i.second);
        }
    }
}

} // namespace

