function solution(progresses, speeds) {
    var answer = [];
    
    var num_of_progresses = progresses.length;
    console.log(num_of_progresses);
    
    while(num_of_progresses > 0)
        {
            progresses.forEach(function(element, index) {
                progresses[index] = element + speeds[index];
            })
            
            var cnt = 0;

            for(var progress of progresses)
            {
              if(progress >= 100) cnt+=1;
              else break;
            }
          
            if(cnt != 0) answer.push(cnt);
            num_of_progresses -= cnt;
            
            while(cnt > 0)
                {
                    cnt--;
                    progresses.shift();
                    speeds.shift();
                }  
        }
    
    return answer;
}
