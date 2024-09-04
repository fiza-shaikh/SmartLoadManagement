# SmartLoadManagement

### Problem Statement:
Electric vehicles (EVs) are becoming increasingly popular, leading to a growing demand for efficient and user-friendly charging solutions. As more EV users seek to charge their vehicles simultaneously, managing charging schedules and prioritizing users becomes challenging. Additionally, users are often unaware of the available time slots and may miss out on incentives offered by charging stations. There is a need for a smart load management system that can handle these challenges by efficiently scheduling charging times, applying incentives, and providing users with clear data on their charging history.

### Solution:
The **SmartLoadManagement** project addresses these challenges by providing a Linux-based C++ application that manages EV charging schedules effectively. The system allows users to:

1. **Schedule Charging**: Users can schedule their charging by providing their user ID, date, and time. The system prioritizes the first user if multiple users attempt to book the same slot, adjusting subsequent users' schedules by increments of 5 minutes. If the initial time slot is unavailable, the user is prompted to confirm or choose an alternative slot from the available ones.

2. **Apply Incentives**: For every $5 spent at an EVgo charging location, users earn 5 points towards future charging credits. This feature encourages users to utilize the charging stations more frequently.

3. **Analyze Data**: Users can view their charging history by entering their user ID. The system displays the dates and times when the vehicle was charged, helping users track their charging patterns.

4. **Exit**: Users can exit the application, ensuring a seamless user experience.

This project offers a comprehensive solution for managing EV charging loads, ensuring fair access to charging slots, and promoting efficient use of resources through incentives.

#Commands to run the project
Step 1:
Download the project from github
Open terminal

Step2:
Write 
>make clean
>make 
>./SmartLoadManagement

