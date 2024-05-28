<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
  </head>
<body>
    <h1>Setting Up Laptop to Send Data to the Microcontroller</h1>
    <h2>Step 1: Create the boot.py File</h2>
    <p>Create the <code>boot.py</code> file in MicroPython, which essentially connects to the Wi-Fi network.</p>
    <h2>Step 2: Create the Server</h2>
    <p>Create the server in MicroPython, which will accept the data sent to it.</p>
    <h3>i) Define a Host and Port</h3>
    <p>Define the host and port for your server.</p>
    <h3>ii) Make a Socket Connection</h3>
    <p>Make a socket connection using:</p>
    <pre><code>socket.socket(socket.AF_INET, socket.SOCK_STREAM)</code></pre>
    <h3>iii) Bind the Socket</h3>
    <p>Bind the socket to listen to the host and port.</p>
    <h3>iv) Listen for Connections</h3>
    <p>Listen for one connection at a time using:</p>
    <pre><code>server.listen(1)</code></pre>
    <h3>v) Receive and Process Data</h3>
    <p>Make a loop in which you wait for a connection:</p>
    <pre><code>
while True:
    client_socket, client_address = server.accept()
    data = client_socket.recv(1024)
    print(f"data: {data.decode('utf-8')}")
    client_socket.close()
</code></pre>
    <h1>ROS/Ubuntu Commands Guide</h1>
    <p>This guide provides an overview of some basic commands used in ROS/Ubuntu projects. Note that advanced procedures such as adding Gazebo or modifying launch files are not covered here. This guide aims to help you get started.</p>
    <h2>Adjusting Swap File Configuration</h2>
    <ol>
        <li>
            <code>sudo dphys-swapfile swapoff</code>
            <p><strong>Purpose:</strong> Disable swapping temporarily.<br>
            <strong>Description:</strong> Stops the swapping process, allowing for changes to the swap file configuration.</p>
        </li>
        <li>
            <code>sudo nano /etc/dphys-swapfile</code>
            <p><strong>Purpose:</strong> Edit the swap file configuration.<br>
            <strong>Description:</strong> Opens the swap file configuration file in the Nano text editor, allowing you to modify parameters such as swap size.</p>
        </li>
        <li>
            Make changes to <code>CONF_SWAPSIZE</code> and press <code>ctrl+x</code>, <code>y</code>, <code>enter</code>
            <p><strong>Purpose:</strong> Adjust swap file size.<br>
            <strong>Description:</strong> Modify the <code>CONF_SWAPSIZE</code> parameter to set the desired swap size, then save the changes and exit Nano.</p>
        </li>
        <li>
            <code>sudo dphys-swapfile setup</code>
            <p><strong>Purpose:</strong> Apply the new swap file configuration.<br>
            <strong>Description:</strong> Configures the system with the updated swap file settings.</p>
        </li>
        <li>
            <code>sudo dphys-swapfile swapon</code>
            <p><strong>Purpose:</strong> Enable swapping with the new configuration.<br>
            <strong>Description:</strong> Activates swapping using the modified swap file settings.</p>
        </li>
    </ol>
    <h2>Setting Up ROS Workspace and RPLidar</h2>
    <ol>
        <li>
            <code>cd /home/ubuntu</code>
            <p><strong>Purpose:</strong> Change directory to the home folder.<br>
            <strong>Description:</strong> Navigates to the home directory to create a new catkin workspace.</p>
        </li>
        <li>
            <code>mkdir catkin_ws</code>
            <p><strong>Purpose:</strong> Create a new catkin workspace.<br>
            <strong>Description:</strong> Creates a directory named <code>catkin_ws</code> to serve as a workspace for ROS packages.</p>
        </li>
        <li>
            <code>catkin_init_workspace</code>
            <p><strong>Purpose:</strong> Initialize the catkin workspace.<br>
            <strong>Description:</strong> Initializes the newly created <code>catkin_ws</code> as a ROS catkin workspace.</p>
        </li>
        <li>
            <code>git clone [repo for rplidar]</code>
            <p><strong>Purpose:</strong> Clone the repository for RPLidar.<br>
            <strong>Description:</strong> Retrieves the RPLidar ROS package from the specified Git repository.</p>
        </li>
        <li>
            <code>catkin_make</code>
            <p><strong>Purpose:</strong> Build the ROS packages.<br>
            <strong>Description:</strong> Compiles the ROS packages in the catkin workspace.</p>
        </li>
        <li>
            <code>source devel/setup.bash</code>
            <p><strong>Purpose:</strong> Source the workspace setup file.<br>
            <strong>Description:</strong> Sets up the ROS environment for the current terminal session.</p>
        </li>
        <li>
            <code>sudo chmod 666 /dev/ttyUSB0</code>
            <p><strong>Purpose:</strong> Change permissions for USB device.<br>
            <strong>Description:</strong> Grants read and write permissions to <code>/dev/ttyUSB0</code> to allow communication with the RPLidar sensor.</p>
        </li>
        <li>
            <code>killall -9 roscore</code>
            <p><strong>Purpose:</strong> Terminate the running ROS core.<br>
            <strong>Description:</strong> Stops the currently running ROS core.</p>
        </li>
        <li>
            <code>roscore</code>
            <p><strong>Purpose:</strong> Start a new ROS core.<br>
            <strong>Description:</strong> Initiates a new ROS core to serve as the communication backbone.</p>
        </li>
        <li>
            <code>roslaunch rplidar_ros rplidar.launch</code>
            <p><strong>Purpose:</strong> Launch RPLidar ROS node.<br>
            <strong>Description:</strong> Starts the RPLidar ROS node with the specified launch file.</p>
        </li>
        <li>
            After running it, check for errors...
            <p><strong>Purpose:</strong> Diagnose common errors during RPLidar setup.<br>
            <strong>Description:</strong> Inspects for errors such as "operation timed out" or "scan not started," usually caused by incorrect wiring. Recheck and reconnect if necessary.</p>
        </li>
    </ol>
    <h2>Creating and Running a Custom ROS Package</h2>
    <ol>
        <li>
            <code>cd /home/ubuntu/custom_workspace</code>
            <p><strong>Purpose:</strong> Change directory to a custom workspace.<br>
            <strong>Description:</strong> Navigates to a custom workspace for creating a new ROS package.</p>
        </li>
        <li>
            <code>catkin_create_pkg custom_package rospy</code>
            <p><strong>Purpose:</strong> Create a new ROS package.<br>
            <strong>Description:</strong> Generates a new ROS package named <code>custom_package</code> with <code>rospy</code> as a dependency.</p>
        </li>
        <li>
            <code>cd scripts</code>
            <p><strong>Purpose:</strong> Change directory to the scripts folder.<br>
            <strong>Description:</strong> Navigates to the scripts folder within the newly created package.</p>
        </li>
        <li>
            Create and edit Python scripts
            <p><strong>Purpose:</strong> Develop custom ROS nodes.<br>
            <strong>Description:</strong> Creates <code>Publisher.py</code> and <code>Subscriber.py</code> scripts, adds code to them, and makes them executable using <code>chmod +x</code>.</p>
        </li>
        <li>
            <code>catkin_make</code>
            <p><strong>Purpose:</strong> Build the ROS packages.<br>
            <strong>Description:</strong> Compiles the ROS packages in the custom workspace.</p>
        </li>
        <li>
            <code>source devel/setup.bash</code>
            <p><strong>Purpose:</strong> Source the workspace setup file.<br>
            <strong>Description:</strong> Sets up the ROS environment for the current terminal session.</p>
        </li>
        <li>
            <code>rosrun custom_package Publisher.py</code>
            <p><strong>Purpose:</strong> Run the custom Publisher node.<br>
            <strong>Description:</strong> Executes the custom Python script that acts as a ROS Publisher node.</p>
        </li>
        <li>
            <code>rosrun custom_package Subscriber.py</code>
            <p><strong>Purpose:</strong> Run the custom Subscriber node.<br>
            <strong>Description:</strong> Executes the custom Python script that acts as a ROS Subscriber node.</p>
        </li>
    </ol>
    <h2>Additional ROS Commands</h2>
    <ol>
        <li>
            <code>rostopic list</code>
            <p><strong>Purpose:</strong> List active ROS topics.<br>
            <strong>Description:</strong> Displays a list of currently active ROS topics.</p>
        </li>
        <li>
            <code>rostopic echo /scan</code> or any other topic
            <p><strong>Purpose:</strong> Monitor topic messages.<br>
            <strong>Description:</strong> Prints the messages published on the specified ROS topic (e.g., <code>/scan</code>).</p>
        </li>
    </ol>
    <h2>Running SLAM Algorithms</h2>
    <ol>
        <li>
            If doing Hector SLAM...
            <p><strong>Purpose:</strong> Run Hector SLAM after RPLidar setup.<br>
            <strong>Commands:</strong>
            <pre><code>roslaunch hector_slam_ros tutorial.launch
rostopic echo /map or /mapupdates</code></pre>
            <strong>Description:</strong> Initiates Hector SLAM launch file for mapping and visualization.</p>
        </li>
        <li>
            If running Gmapping...
            <p><strong>Purpose:</strong> Run Gmapping algorithm.<br>
            <strong>Commands:</strong>
            <pre><code>roslaunch turtlebot3_slam turtlebot3_slam.launch slam_methods:=gmapping</code></pre>
            <strong>Description:</strong> Launches Gmapping SLAM algorithm for mapping using TurtleBot3. Change the model using <code>export model=wafflepi</code> or any other before running the algorithm or add your model here.</p>
        </li>
    </ol>  
    <h2>Saving a Map</h2>
    <ol>
        <li>
            <code>rosrun map_server map_saver -f ~/name</code>
            <p><strong>Purpose:</strong> Save the generated map.<br>
            <strong>Description:</strong> Utilizes the <code>map_server</code> tool to save the generated map with the specified filename (e.g., <code>~/name</code>).</p>
        </li>
    </ol>
    <h2>Running the Algorithm in Gazebo Environment</h2>
    <ol>
        <li>Move to the directory <code>artist_ws</code></li>
        <li><code>catkin_make</code></li>
        <li><code>source devel/setup.bash</code></li>
        <li><code>roslaunch astar_search algorithm_visualization.launch</code></li>
    </ol>
    <p>After running, the results are given as:</p>
</body>
</html>
