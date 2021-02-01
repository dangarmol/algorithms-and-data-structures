class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        intervals.sort(key=lambda x: x[0])
        
        current = intervals[0][0] if len(intervals) > 0 else None
        
        for meeting in intervals:
            if current > meeting[0]:
                return False
            else:
                current = meeting[1]
            
        return True
