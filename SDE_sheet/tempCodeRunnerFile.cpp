while(mp.find(nums[prev]-1)!= mp.end() && !vis[mp.find(nums[prev]-1)->second]){
            //     cout<<" inside pre "<<endl;
            //     count++;
            //     prev= mp.find(nums[prev]-1)->second;
            //     vis[prev] = true;
            // }
            // while(mp.find(nums[next]+1)!= mp.end() && !vis[mp.find(nums[next]+1)->second]){
            //     cout<<" inside next "<<endl;
            //     count++;
            //     next= mp.find(nums[next]+1)->second;
            //     vis[next] = true;
            // }