## 1. Explain the problem you tackled and its importance/significance
The problem that we wanted to solve was the lack of budget-friendly plant health monitors that were compatible with both small-scale (house plants) and large-scale (greenhouse) gardens. Its significance in the current market is that solutions for small-scale areas are relatively cheap and compact, but solutions for large-scale areas can be bulky and expensive, or multiple small devices are requried which have no way of interacting with one another.


## 2. Explain the solution you proposed and what you built
The solution that we proposed was a compact device that could be installed anywhere and monitor the surrounding environment. The solution we built was a modular device that, while not as contained as we would have liked,  allows for the sensors to be positioned according to what the user needs.

## 3. Describe who are potential benefactors
The main potential benefactors are those who have plants growing in a larger area than a plant pot (such as a greenhouse), where the monitoring of the area is more beneficial due to the various number of plants they have growing. Or for someone with a smaller garden, such as houseplants, who does not have thetime to be checking on plants everyday.


## 4. Explain overall architecture

Our general architecture uses a cloud component for the majority of the monitoring and alerting, with a physical display on the devce being used in order to convey basic information to the user in a timely fashion. Thingsboard, our cloud component, is used to display historical data to the user to allow them to track trends, with the screen being used to allow the user to view realtime information.


## 5. Demonstrate all the functionalities
/ Explain here what data we are gathering and how that will interact with ThingsBoard /
Temp, Humidity, Light - dispayed using graphs on things board

## > Explain all the functionalities you initially planned to develop but failed to do so
We planned on having a Raspberry Pi to act as a local server so we wouldn't have to send the data to an external location (such as ThingsBoard, which we are using), we failed to implement this as we did not have access to a Raspberry Pi outside of the scheduled lab sessions.

we intedned to use SMS or push notifictaions to send messages to the user


## > Explain the reasons for the failure to implement each feature

We did not dedicate enough time to the reserach and set up required fro SMS delivery

## 6. Explain the main challenges you faced
The Arduino stopped being correctly identified by any device we attempted to connect it to. This in turn brought our development of all listed functionalities to a halt as we could no longer implement our extended functionalities, and we could no longer ensure that any modifications to the program would work as intended.


## 7. Describe the lessons you learnt and things you would do differently if you were to do it again
We learnt that having a backup method available is crucial as problems can occur at any time, and not having something to fall back on is a mistake on our part. When doing this project again, we would find a way to obtain a backup option early on so in a worst-case scenario, we would have something to fall back on.


## 8. Explain how you could (would) develop this project further

We would first implement the SMS system as it would be a great quality of life feature for the user as it would make using the system much more streamlined, as the LCD screen is very limited in its character count without using scrolling, which can be hard to read.

We would further develop the ThingsBoard system to inlude some more data visualisation as well as adding in more intercativity within the page, for example multiple pages and buttons that will allow you to customise and interact with the monitoring device.

