from setuptools import setup
package_name = 'supervisor'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Pascal Voser',
    maintainer_email='voserp@gmail.com',
    description='Node which supervises all other nodes and provides feedback',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'supervisor_node = supervisor.supervisor_node:main'
        ],
    },
)
