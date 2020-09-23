            std::vector<int> allTasks, solvedTasks;
            for (int i = 0; i < tasks; ++i)
                allTasks.emplace_back(i + 1);
            for (size_t i = 2; i < word.size(); ++i)
                solvedTasks.emplace_back(string_to_int(word[i]));
            std::vector<int> unsolvedTasks(tasks - solvedTasks.size());
            std::set_difference(allTasks.begin(), allTasks.end(),
                solvedTasks.begin(), solvedTasks.end(), unsolvedTasks.begin());
            for (int x : unsolvedTasks)
                std::cout << x << " ";
