            std::vector<char> allTasks, solvedTasks;
            for (int i = 0; i < tasks; ++i)
                allTasks.emplace_back(i + 'A');
            for (size_t i = 2; i < word.size(); ++i)
                solvedTasks.emplace_back(word[i][0]);
            std::vector<char> unsolvedTasks(tasks - solvedTasks.size());
            std::set_difference(allTasks.begin(), allTasks.end(),
                solvedTasks.begin(), solvedTasks.end(), unsolvedTasks.begin());
            for (char x : unsolvedTasks)
                std::cout << x << " ";
